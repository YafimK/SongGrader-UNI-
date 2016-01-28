/**
 * @file	TagMatchGrader.cpp
 *
 * @brief	Implements the tag match grader class.
 */

#include "TagMatchGrader.h"

const static int QUERY_WORD_FOUND_FLAG = 1;

TagMatchGrader::TagMatchGrader(const int& tagMatchWeight)
		:GradingCategory(tagMatchWeight)
{
}


double TagMatchGrader::catagoryGrader(const std::unordered_map<std::string, unsigned>& gradingTarget,
									  const std::string& queryWord)
{
	unsigned int grade = DEFAULT_GRADE;

	if(QUERY_WORD_FOUND_FLAG == gradingTarget.count(queryWord))
	{
		grade = (this->getGradingCatagoryWeight()) * (gradingTarget.at(queryWord));
	}

	return grade;
}


TagMatchGrader::~TagMatchGrader() = default;