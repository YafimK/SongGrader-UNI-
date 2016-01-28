#pragma once

#include "GradingCatagory.h"

#ifndef _INSTRUMENTS_GRADING_CATAGORY_H_
#define _INSTRUMENTS_GRADING_CATAGORY_H_

#include <set>

/**
 * @class	InstrumentsMatchGrader InstrumentsMatchGrader.h InstrumentsMatchGrader.h
 *
 * @brief	The instruments match test calss
 */

class InstrumentsMatchGrader : public GradingCategory
{
public:

	/**
	 * @fn	unsigned InstrumentsMatchGrader::catagoryGrader(const std::multiset<std::string>&
	 * songInstruments, const std::string& queryWord) const;
	 *
	 * @brief	Catagory grader.
	 *
	 * @param	songInstruments	The song instruments.
	 * @param	queryWord	   	The query word.
	 *
	 * @return	the score of the test
	 */

	unsigned catagoryGrader(const std::multiset<std::string>& songInstruments, const std::string&
							queryWord) const;

	/**
	 * @fn	explicit InstrumentsMatchGrader::InstrumentsMatchGrader(const int& matchWeight);
	 *
	 * @brief	Constructor.
	 *
	 * @param	matchWeight	The match weight of the parameter
	 */

	explicit InstrumentsMatchGrader(const int& matchWeight);
};

#endif // !_GRADING_CATEGORY_H_

