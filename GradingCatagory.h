#pragma once

#include <string>

#ifndef _GRADING_CATEGORY_H_
#define _GRADING_CATEGORY_H_


const static unsigned int DEFAULT_GRADE = 0;

const static std::string TAG_MATCH = "tagMatchScore";
const static std::string LYRICS_MATCH = "lyricsMatchScore";
const static std::string INSTRUMENTS_MATCH = "instrumentMatchScore";
const static std::string BPM_MATCH = "bpmLikelihoodWeight";
/**
 * @file	GradingCatagory.cpp
 *
 * @brief	Implements the basic grading catagory class.
 */
class GradingCategory
{
public:

	/**
	 * @fn	explicit GradingCategory::GradingCategory(const int& gradingCatagoryWeight);
	 *
	 * @brief	Constructor.
	 *
	 * @param	gradingCatagoryWeight	The grading catagory weight.
	 */

	explicit GradingCategory(const unsigned int& gradingCatagoryWeight);

	/**
	 * @fn	const unsigned int& GradingCategory::getGradingCatagoryWeight() const;
	 *
	 * @brief	Gets grading catagory weight.
	 *
	 * @return	The grading catagory weight.
	 */

	const unsigned int& getGradingCatagoryWeight() const;

	/**
	 * @fn	virtual GradingCategory::~GradingCategory() = default;
	 *
	 * @brief	Destructor./
	 */

	virtual ~GradingCategory() = default;

private:
	/** @brief	The grading catagory weight. */
	unsigned int _gradingCatagoryWeight;
};

#endif // !GradingCategory

