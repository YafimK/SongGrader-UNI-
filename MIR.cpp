/**
 * @file	MIR.cpp
 *
 * @brief	Implements the mir class.
 */

#include <assert.h>
#include <fstream>
#include <vector>

#include "SongParser.h"
#include "ParametersParser.h"
#include "SongGrader.h"

/**
 * @def	IO_ERROR_MSG();
 *
 * @brief	A macro that defines I/O error message.
 */

#define IO_ERROR_MSG "I\\O error: "


/** @brief	songs file path index in the command line*/
const static int SONGS_FILE_ARGV_INDX = 1;
/** @brief	learned parameters file path index in the command line*/
const static int LEARNED_PARAM_FILE_ARGV_INDX = 2;
/** @brief	queries file path index in the command line*/
const static int QUERIES_FILE_ARGV_INDX = 3;
/** @brief	The possible and required arguments number. */
const static int REQUIRED_ARGUMENTS_NUMBER = 4;

/**
 * @fn	void fileLoadFailure(const std::string& fileName);
 *
 * @brief	show message in case File load failure.
 *
 * @param	fileName	name of the file.
 */
void fileLoadFailure();

void destructor(std::vector<Song*>& songCol, std::map<std::string, GradingCategory*>& songGraders);

/**
 * @fn	int main(int argc, char* argv[])
 *
 * @brief	Main entry-point for this application.
 *
 * @param	argc	Number of command-line arguments.
 * @param	argv	Array of command-line argument strings.
 *
 * @return	Exit-code for the process - 0 for success, else an error code.
 */

int main(int argc, char* argv[])
{

	assert(argc == REQUIRED_ARGUMENTS_NUMBER);
	//the std::vector which will hold the songs
	std::vector<Song*> songCollection;
	std::map<std::string, GradingCategory*> gradersCollection;
	std::ifstream processedFile;

	for(int i = 1; i < argc; i ++)
	{
		std::string filePath = argv[i];

		processedFile.open(filePath, std::ifstream::in);
		if(processedFile.is_open())
		{
			switch(i)
			{
				case (SONGS_FILE_ARGV_INDX): //songs data file
					SongParser::initillizer();
					songCollection = SongParser::parseSong(processedFile);
					break;
				case (LEARNED_PARAM_FILE_ARGV_INDX):
					ParametersParser::getInstance();
					gradersCollection = ParametersParser::_parseParameterFile(processedFile);
					break;
				case (QUERIES_FILE_ARGV_INDX):
					SongGrader::getSongGraderInstance();
					SongGrader::parseQueryFile(processedFile);
					SongGrader::runGrading(songCollection, gradersCollection);
					break;
			}
			processedFile.close();
		}
		else
		{
			fileLoadFailure();
			break;
		}
	}

	destructor(songCollection, gradersCollection);
	return 0;
}

/**
 * @fn	void destructor(std::vector<Song*>& songCol, std::map<std::string, GradingCategory*>&
 * songGraders)
 *
 * @brief	Destructors.
 *
 * @param [in,out]	songCol	   	[in,out] If non-null, the song collection
 * @param [in,out]	songGraders	[in,out] If non-null, the song graders.
 */

void destructor(std::vector<Song*>& songCol, std::map<std::string, GradingCategory*>& songGraders)
{

	for(unsigned int i = 0; i < songCol.size(); ++ i)
	{
		delete songCol[i];
	}

	for(std::pair<std::string, GradingCategory*> target:songGraders)
	{
		delete target.second;
	}

	ParametersParser::destructor();
	SongParser::songParserDestructor();
	SongGrader::_songGraderDestructor();

}

/**
 * @fn	void fileLoadFailure()
 *
 * @brief	File load failure.
 */

void fileLoadFailure()
{
	perror(IO_ERROR_MSG);
	return;
}
