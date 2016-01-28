/**
 * @file	BpmGradingCatagory.cpp
 *
 * @brief	Implements the bpm grading match test class.
 */

#include <cmath>
#include "BpmGradingCatagory.h"

/** @brief	The query word found flag. */
const static int QUERY_WORD_FOUND_FLAG = 1;


 
double BpmGradingCatagory::catagoryGrader(const double& songBpm, const std::string& queryWord)
{
	double grade = DEFAULT_GRADE;

	if(QUERY_WORD_FOUND_FLAG == this->getBpmWordsCollection().count(queryWord))
	{
		//finds the std::pair of deviation and average for the appropriate query word
		std::pair<double, double> tempPair = this->getBpmWordsCollection().at(queryWord);

		double bpmAverage = tempPair.first;
		double bpmDivition = tempPair.second;

		grade = floor(exp(- ((songBpm - bpmAverage) * (songBpm - bpmAverage))
				/ (2 * (bpmDivition * bpmDivition)))
				* (this->getGradingCatagoryWeight()));
	}

	return grade;
}


BpmGradingCatagory::BpmGradingCatagory(const int& bpmMatchWeight,
									   std::map<std::string, std::pair<double, double>>& bpmValues)
									   :GradingCategory(bpmMatchWeight)
{
	this->_bpmWordsCollection = bpmValues;
}

const std::map<std::string, std::pair<double, double>>& BpmGradingCatagory::getBpmWordsCollection()
												const
{
	return this->_bpmWordsCollection;
}
