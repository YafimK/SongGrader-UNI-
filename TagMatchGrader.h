#pragma once

#include "GradingCatagory.h"

#ifndef _TAG_MATCH_GRADER_H_
#define _TAG_MATCH_GRADER_H_

#include <unordered_map>



/**
 * @class	TagMatchGrader TagMatchGrader.h TagMatchGrader.h
 *
 * @brief	a grader for the tag match test
 */

class TagMatchGrader : public GradingCategory
{
public:

	/**
	 * @fn	virtual TagMatchGrader::~TagMatchGrader();
	 *
	 * @brief	Destructor.
	 */

	virtual ~TagMatchGrader();

	/**
	 * @fn	TagMatchGrader::TagMatchGrader(const int& tagMatchWeight);
	 *
	 * @brief	Constructor./
	 *
	 * @param	tagMatchWeight	The tag match weight.
	 */

	TagMatchGrader(const int& tagMatchWeight);

	/**
	 * @fn	double TagMatchGrader::catagoryGrader (const std::unordered_map<std::string, unsigned int>& gradingTarget, const std::string& queryWord);
	 *
	 * @brief	Tag Match grader.
	 *
	 * @param	gradingTarget	the song tags list.
	 * @param	queryWord	 	The query word.
	 *
	 * @return	A double.
	 */

	double catagoryGrader
			(const std::unordered_map<std::string, unsigned int>& songTagList, const std::string& queryWord);
};

#endif // !_TAG_MATCH_GRADER_H

