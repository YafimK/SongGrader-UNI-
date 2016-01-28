#pragma once

#include "GradingCatagory.h"

#ifndef _LYRICS_MATCH_GRADER_H_
#define _LYRICS_MATCH_GRADER_H_

#include <set>



/**
 * @class	LyricsMatchGrader LyricsMatchGrader.h LyricsMatchGrader.h
 *
 * @brief	The lyrics match grader.
 */

class LyricsMatchGrader : public GradingCategory
{
public:

	/**
	 * @fn	unsigned LyricsMatchGrader::catagoryGrader(const std::multiset<std::string>& lyrics,
	 * const std::string& queryWord) const;
	 *
	 * @brief	Catagory grader.
	 *
	 * @param	lyrics   	The lyrics.
	 * @param	queryWord	The query word.
	 *
	 * @return	An unsigned.
	 */

	unsigned catagoryGrader(const std::multiset<std::string>& lyrics, const std::string& queryWord)
						    const;

	/**
	 * @fn	LyricsMatchGrader::LyricsMatchGrader(const int& lyricsMatchGrade);
	 *
	 * @brief	Constructor.
	 *
	 * @param	lyricsMatchGrade	The lyrics match grade.
	 */

	LyricsMatchGrader(const int& lyricsMatchGrade);
};

#endif // !_LYRICS_MATCH_GRADER_H_

