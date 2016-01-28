/**
 * @file	LyricsMatchGrader.cpp
 *
 * @brief	Implements the lyrics match grader class.
 */

#include "LyricsMatchGrader.h"

/** @brief	The query word not found flag. */
const static int QUERY_WORD_NOT_FOUND_FLAG = 0;

unsigned LyricsMatchGrader::catagoryGrader(const std::multiset<std::string>& lyrics,
										   const std::string& queryWord) const
{
	unsigned int grade = DEFAULT_GRADE;
	size_t wordOccourences = lyrics.count(queryWord);

	if(QUERY_WORD_NOT_FOUND_FLAG != lyrics.count(queryWord))
	{
		grade = (this->getGradingCatagoryWeight()) * (wordOccourences);
	}

	return grade;
}


LyricsMatchGrader::LyricsMatchGrader(const int& lyricsMatchGrade)
									 :GradingCategory(lyricsMatchGrade)
{
};
