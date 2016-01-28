/**
 * @file	SongGrader.cpp
 *
 * @brief	Implements the song grader class.
 */

#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <iostream>
#include <assert.h>
#include <algorithm>
#include "SongGrader.h"

/** @brief	The ssong grader instance pointer. nuliified at start */
SongGrader* SongGrader::s_songGraderInstance = nullptr;
std::vector<std::string> SongGrader::s_queryWordCollection;

/** @brief	The minimal song grade to be shown. */
const static double MINIMAL_SONG_GRADE_TO_BE_SHOWN = 0.00;



SongGrader* SongGrader::getSongGraderInstance()
{
	if(! s_songGraderInstance) //check if the singleton was initializeed
	{
		s_songGraderInstance = new SongGrader();
	}
	return s_songGraderInstance;
}



const std::vector<std::string>& SongGrader::getQueryWordsCollection()
{
	return s_queryWordCollection;
}



void SongGrader::parseQueryFile(std::ifstream& sourceFile)
{
	std::string line = DEFAULT_STRING;

	while(sourceFile.good())
	{
		getline(sourceFile, line);
		if(! line.empty())
		{
			s_queryWordCollection.push_back(line);
		}

	}
}


void SongGrader::runGrading(std::vector<Song*>& songs, std::map<std::string, GradingCategory*>& gradingTools)
{
	assert((getQueryWordsCollection()).size() != 0);
	std::vector<std::pair<Song*, double>> rankedSongs;
	for(std::string queryWord: s_queryWordCollection)
	{
		rankedSongs.clear();
		for(Song* testedSong : songs)
		{
			double songMatchGrade = testedSong->evaluateMyGrade(gradingTools, queryWord);
			if(MINIMAL_SONG_GRADE_TO_BE_SHOWN < songMatchGrade)
			{
				rankedSongs.push_back(std::make_pair(testedSong, songMatchGrade));
			}
		}
		stable_sort(rankedSongs.begin(), rankedSongs.end(), _compareSongRank);
		_printSongRanking(rankedSongs, queryWord);
	}
}



bool SongGrader::_compareSongRank(std::pair<Song*, double> firstSong, std::pair<Song*, double> secondSong)
{
	return (firstSong.second > secondSong.second);
}



void SongGrader::_printSongRanking(std::vector<std::pair<Song*, double>>& rankedSong, std::string& queryWord)
{
	std::cout << RESULT_SEPRATOR << std::endl;
	std::cout << QUERY_WORD_LABEL << queryWord << std::endl << std::endl;
	for(std::pair<Song*, double> song: rankedSong)
	{
		Song* tempSong = song.first;
		double songRank = song.second;
		std::cout << (*tempSong).getSongTitle() << TAGS_SEPRATOR << songRank << TAGS_SEPRATOR;
		(*tempSong).printSongSpecialTags();
		std::cout << std::endl;
	}
}



void SongGrader::_songGraderDestructor()
{
	if(s_songGraderInstance != nullptr)
	{
		delete SongGrader::s_songGraderInstance;
		SongGrader::s_songGraderInstance = nullptr;
	}

}
