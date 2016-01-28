

#include "Song.h"
#include "TagMatchGrader.h"

/**
 * @file	Song.cpp
 *
 * @brief	Implements the song class.
 */

double Song::evaluateMyGrade(const std::map<std::string, GradingCategory*>& graders,
							 const std::string& targetString)
{
	TagMatchGrader tagMatchGrader = *dynamic_cast<TagMatchGrader*>(graders.at(TAG_MATCH));
	double matchScore = tagMatchGrader.catagoryGrader(this->getSongTags(), targetString);
	return matchScore;
}



Song::Song(const std::string& songTitle, const std::unordered_map<std::string, unsigned>&
           sourceSongTags):_title(songTitle), _songTags(sourceSongTags)
{
}



std::unordered_map<std::string, unsigned>& Song::getSongTags()
{
	return this->_songTags;
}


const std::string& Song::getSongTitle() const
{
	return _title;
}
