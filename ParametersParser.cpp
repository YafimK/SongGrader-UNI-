/**
 * @file	ParametersParser.cpp
 *
 * @brief	Implements the parameters parser class.
 */

#include "ParametersParser.h"
#include <assert.h>
#include "TagMatchGrader.h"
#include "LyricsMatchGrader.h"
#include "InstrumentsMatchGrader.h"
#include "BpmGradingCatagory.h"


/** @brief	. */
const static std::string CATAGORY_SEPRATOR = ": ";
/** @brief	The bpm word catagory seprator. */
const static std::string BPM_WORD_CATAGORY_SEPRATOR = " , ";

/** @brief	The parameters parser instance pointer. nuliified at start */
ParametersParser* ParametersParser::s_parameterParserInstance = nullptr;



void ParametersParser::destructor()
{
	if(s_parameterParserInstance != nullptr)
	{
		delete ParametersParser::s_parameterParserInstance;
		ParametersParser::s_parameterParserInstance = nullptr;
	}

}

ParametersParser* ParametersParser::getInstance()
{
	if(! ParametersParser::s_parameterParserInstance)
	{
		ParametersParser::s_parameterParserInstance = new ParametersParser();

		return ParametersParser::s_parameterParserInstance;
	}
	return ParametersParser::s_parameterParserInstance;
}

std::map<std::string, GradingCategory*> ParametersParser::_parseParameterFile(std::ifstream& sourceFile)
{
	std::map<std::string, GradingCategory*> result;

	std::string line = "";

	size_t pos = 0;

	getline(sourceFile, line);
	assert(line.find(TAG_MATCH) != std::string::npos); //validate the structure of the file
	pos = TAG_MATCH.size() + CATAGORY_SEPRATOR.size();
	int tagMatchWeight = stoi(line.substr(pos));
	assert(tagMatchWeight > 0);
	GradingCategory* tempGrader;
	tempGrader = new TagMatchGrader(tagMatchWeight);
	result.insert(std::make_pair(TAG_MATCH, tempGrader));

	getline(sourceFile, line);
	assert(line.find(LYRICS_MATCH) != std::string::npos); //validate the structure of the file
	pos = LYRICS_MATCH.size() + CATAGORY_SEPRATOR.size();
	int lyricsMatchWeight = stoi(line.substr(pos));
	assert(lyricsMatchWeight > 0);
	tempGrader = new LyricsMatchGrader(lyricsMatchWeight);
	result.insert(std::make_pair(LYRICS_MATCH, tempGrader));

	getline(sourceFile, line);
	assert(line.find(INSTRUMENTS_MATCH) != std::string::npos); //validate the structure of the file
	pos = INSTRUMENTS_MATCH.size() + CATAGORY_SEPRATOR.size();
	int instrumentsMatchWeight = stoi(line.substr(pos));
	assert(instrumentsMatchWeight > 0);
	tempGrader = new InstrumentsMatchGrader(instrumentsMatchWeight);
	result.insert(std::make_pair(INSTRUMENTS_MATCH, tempGrader));

	getline(sourceFile, line);
	assert(line.find(BPM_MATCH) != std::string::npos); //validate the structure of the file
	pos = BPM_MATCH.size() + CATAGORY_SEPRATOR.size();
	int bpmWeight = stoi(line.substr(pos));
	assert(bpmWeight > 0);
	getline(sourceFile, line);

	std::map<std::string, std::pair<double, double>>
			bpmCatagories = ParametersParser::extractBpmWordList(sourceFile, line);

	tempGrader = new BpmGradingCatagory(bpmWeight, bpmCatagories);
	result.insert(std::make_pair(BPM_MATCH, tempGrader));
	return result;
}

std::map<std::string, std::pair<double, double>> ParametersParser::extractBpmWordList(std::ifstream&
																					  sourceFile,
																					  std::string&
																					  line)
{
	std::map<std::string, std::pair<double, double>> bpmCatagories;
	size_t pos;

	//read each bpm known word into the std::map which will hold them
	while(sourceFile.good())
	{
		if(line.empty())
		{
			break;
		}
		std::string bpmCatagoryTitle = line.substr(0, line.find(CATAGORY_SEPRATOR));
		pos = bpmCatagoryTitle.size() + CATAGORY_SEPRATOR.size();
		double catagoryAverage = stod(line.substr(pos, line.find(BPM_WORD_CATAGORY_SEPRATOR, pos)));
		pos = line.find(BPM_WORD_CATAGORY_SEPRATOR) + BPM_WORD_CATAGORY_SEPRATOR.size();
		double catagoryDivition = stod(line.substr(pos));
		bpmCatagories
				.insert(std::make_pair(bpmCatagoryTitle, std::make_pair(catagoryAverage, catagoryDivition)));
		getline(sourceFile, line);
	}
	return bpmCatagories;
}
