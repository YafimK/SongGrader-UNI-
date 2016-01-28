/**
 * @file	GradingCatagory.cpp
 *
 * @brief	Implements the grading catagory class.
 */

#include "GradingCatagory.h"



GradingCategory::GradingCategory(const unsigned int& gradingCatagoryWeight)
{
	this->_gradingCatagoryWeight = gradingCatagoryWeight;
}


const unsigned int& GradingCategory::getGradingCatagoryWeight() const
{
	return (this->_gradingCatagoryWeight);
}
