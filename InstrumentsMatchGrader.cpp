/**
 * @file	InstrumentsMatchGrader.cpp
 *
 * @brief	Implements the instruments match grader class.
 */

#include "InstrumentsMatchGrader.h"

/** @brief	The query word found flag. */
const static int QUERY_WORD_FOUND_FLAG = 1;



unsigned InstrumentsMatchGrader::catagoryGrader(const std::multiset<std::string>& songInstruments,
												const std::string& queryWord) const
{
	unsigned int grade = DEFAULT_GRADE;

	if(QUERY_WORD_FOUND_FLAG == songInstruments.count(queryWord))
	{
		grade = this->getGradingCatagoryWeight();
	}

	return grade;
}


InstrumentsMatchGrader::InstrumentsMatchGrader(const int& matchWeight)
		:GradingCategory(matchWeight)
{
};
