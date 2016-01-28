
#include "vocalSong.h"
#include "LyricsMatchGrader.h"
#include <iostream>

/**
* @file	vocalSong.cpp
*
* @brief	Implements the vocal/lyricsl song class.
*/

void VocalSong::printSongSpecialTags()
{
	std::cout << "lyrics by: " << this->getSongWriter();
}

double VocalSong::evaluateMyGrade(const std::map<std::string, GradingCategory*>& graders,
	                              const std::string& targetString)
{
	double matchScore = Song::evaluateMyGrade(graders, targetString);

	//knoes that's the correct cast due to getting a value from the graders by apporiate key
	LyricsMatchGrader
			lyricsMatchGrader = *dynamic_cast<LyricsMatchGrader*>(graders.at(LYRICS_MATCH));

	matchScore += lyricsMatchGrader.catagoryGrader(this->getLyrics(), targetString);

	return matchScore;
}


VocalSong::~VocalSong()
{
}


VocalSong::VocalSong(const std::string& songTitle, const std::unordered_map<std::string, unsigned>&
				     songTags, std::multiset<std::string>& sourceSongLyrics, const std::string&
					 sourceSongWriter):Song(songTitle, songTags), _lyrics(sourceSongLyrics),
				     _songWriter(sourceSongWriter)
{
}


const std::multiset<std::string>& VocalSong::getLyrics() const
{
	return _lyrics;
}


const std::string& VocalSong::getSongWriter() const
{
	return _songWriter;
}
