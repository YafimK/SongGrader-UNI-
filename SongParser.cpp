/**
 * @file	SongParser.cpp
 *
 * @brief	Implements the song parser class.
 */

#include <assert.h>
#include <sstream>
#include <fstream>
#include <set>
#include "SongParser.h"
#include "vocalSong.h"
#include "InstrumentalSong.h"



/** @brief	. */
const static std::string SEPARATOR = "=";
/** @brief	The end of songs. */
const static std::string END_OF_SONGS = "***";
/** @brief	The title. */
const static std::string TITLE = "title";
/** @brief	The lyrics. */
const static std::string LYRICS = "lyrics";
/** @brief	Amount to lyrics by. */
const static std::string LYRICS_BY = "lyricsBy";
/** @brief	Amount to performed by. */
const static std::string PERFORMED_BY = "performedBy";
/** @brief	. */
const static std::string CATAGORY_SEPRATOR = ": ";
/** @brief	The bpm. */
const static std::string BPM = "bpm";

/** @brief	The read line space. */
const static char READ_LINE_SPACE = ' ';

/** @brief	The  parser instance pointer. nuliified at start */
SongParser* SongParser::s_songParserInstance = nullptr;

bool SongParser::isVocalSong(std::string& line)
{
	return line.substr(0, LYRICS.size()).compare(LYRICS) == 0;
}



std::vector<Song*> SongParser::parseSong(std::ifstream& sourceFile)
{
	std::vector<Song*> songCollection;

	std::string line = DEFAULT_STRING;

	int lastSong = LAST_SONG_FALSE_FLAG;

	while(sourceFile.good() && ! lastSong)
	{
		if(line.compare(SEPARATOR) != 0)
		{
			getline(sourceFile, line);
			// Expect a line of "="
			if(END_OF_SONGS.compare(line) == 0)
			{
				lastSong = LAST_SONG_TRUE_FLAG;
				break;
			}
		}

		getline(sourceFile, line);
		// Expect a line of "title: ..."
		size_t pos = TITLE.size() + CATAGORY_SEPRATOR.size();
		std::string title = line.substr(pos);
		assert(title.size() > 0);
		getline(sourceFile, line);
		// Expect a line of "tags: {...}" 	 		
		std::vector<std::string> valuesLine = _getWordsList(line);
		std::unordered_map<std::string, unsigned int> tags = _tagReader(valuesLine);

		getline(sourceFile, line);
		// Expect either lyrics or instruments.
		if(isVocalSong(line))
		{
			// Then we have a lyric song

			// Lets get the lyrics:
			valuesLine = _getWordsList(line);
			std::multiset<std::string> lyrics(valuesLine.begin(), valuesLine.end());

			// Lets get the lyricsBy:
			getline(sourceFile, line);
			pos = LYRICS_BY.size() + CATAGORY_SEPRATOR.size();
			std::string lyricsBy = line.substr(pos);
			VocalSong* tempSong = new VocalSong(title, tags, lyrics, lyricsBy);
			songCollection.push_back(tempSong);
		}
		else
		{
			// Then we have an instrumental song
			// Lets get the instruments:
			valuesLine = _getWordsList(line);
			std::multiset<std::string> instruments(valuesLine.begin(), valuesLine.end());

			// Lets get the performedBy:
			getline(sourceFile, line);
			pos = PERFORMED_BY.size() + CATAGORY_SEPRATOR.size();
			std::string performedBy = line.substr(pos);
			InstrumentalSong* tempSong = nullptr;
			// Lets see if we have bpm:
			if(! sourceFile.good())
			{
				break;
			}
			else
			{
				double songBpm = DEFAULT_BPM;
				getline(sourceFile, line);

				if(END_OF_SONGS.compare(line) == 0)
				{
					lastSong = LAST_SONG_TRUE_FLAG;
				}

				if(line.substr(0, BPM.size()).compare(BPM) == 0)
				{
					pos = BPM.size() + CATAGORY_SEPRATOR.size();
					songBpm = stod(line.substr(pos));
					assert(songBpm > 0.00);
					tempSong = new InstrumentalSong(title, tags, instruments, performedBy, songBpm);
				}
				else
				{
					tempSong = new InstrumentalSong(title, tags, instruments, performedBy);
					assert((line.compare(SEPARATOR) == 0) || (line.compare(END_OF_SONGS) == 0));
				}

				assert(tempSong != nullptr); //should be initiliized either with bpm or without
				songCollection.push_back(tempSong);
			}
		}
	}

	return songCollection;
}


std::unordered_map<std::string, unsigned int> SongParser::_tagReader(const std::vector<std::string>& readWordsList)
{
	std::unordered_map<std::string, unsigned int> tagList;

	std::string tag = DEFAULT_STRING;
	int tagValue = 0;

	for(unsigned int i = 0; i < readWordsList.size(); i += 2)
	{
		tag = readWordsList[i];
		tagValue = stoi(readWordsList[1 + i]);
		assert(tagValue > 0);
		tagList.insert(std::make_pair(tag, tagValue));
	}

	return tagList;
}



std::vector<std::string> SongParser::_getWordsList(const std::string& readLine)
{
	size_t startValueSign = readLine.find(LEFT_VALUE_BRACKT) + 1;
	size_t endValueSign = readLine.find(RIGHT_VALUE_BRACKT);
	std::string tempLine = readLine.substr(startValueSign, (endValueSign - startValueSign));
	std::vector<std::string> result;

	std::string token = DEFAULT_STRING;
	std::stringstream tagStream(tempLine);

	while(getline(tagStream, token, READ_LINE_SPACE))
	{
		result.push_back(token);
	}

	return result;
}



SongParser* SongParser::initillizer()
{
	if(! SongParser::s_songParserInstance) //check if the singleton was initializeed
	{
		SongParser::s_songParserInstance = new SongParser();
	}
	return SongParser::s_songParserInstance;
}



void SongParser::songParserDestructor()
{
	if(s_songParserInstance != nullptr)
	{
		delete SongParser::s_songParserInstance;
		SongParser::s_songParserInstance = nullptr;
	}

}
