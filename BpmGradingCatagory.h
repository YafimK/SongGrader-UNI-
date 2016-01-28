#pragma once

#include "GradingCatagory.h"
#include <map>
#include <set>

#ifndef _BPM_GRADING_CATEGORY_H_
#define _BPM_GRADING_CATEGORY_H_



/**
 * @file	BpmGradingCatagory.h
 *
 * @brief	the bpm grading match test class.
 */
class BpmGradingCatagory : public GradingCategory
{
public:
	/**
	* @fn	double BpmGradingCatagory::catagoryGrader(const double& songBpm, const std::string&
	* queryWord)
	*
	* @brief	Catagory grader.
	*
	* @param	songBpm  	The song bpm.
	* @param	queryWord	The query word.
	*
	* @return	A double.
	*/
	double catagoryGrader(const double& songBpm, const std::string& queryWord);
	/**
 * @fn	BpmGradingCatagory::BpmGradingCatagory(const int& bpmMatchWeight, std::map<std::string, std:
 * :pair<double, double>>& bpmValues)
 *
 * @brief	Constructor.
 *
 * @param	bpmMatchWeight   	The bpm match weight.
 * @param [in,out]	bpmValues	The bpm values.
 */

	BpmGradingCatagory(const int& bpmMatchWeight, std::map<std::string, std::pair<double, double>>&
					   bpmValues);

	/**
	 * @fn	const std::map<std::string, std::pair<double, double>>& BpmGradingCatagory::getBpmWords
	 * Collection() const;
	 *
	 * @brief	Gets bpm words collection.
	 *
	 * @return	The bpm words collection.
	 */

	const std::map<std::string, std::pair<double, double>>& getBpmWordsCollection() const;

private:
	/** @brief	Collection of bpm known words. */
	std::map<std::string, std::pair<double, double>> _bpmWordsCollection;
};

#endif // !BPM_GRADING_CATAGORY

