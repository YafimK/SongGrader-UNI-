#pragma once

#include "GradingCatagory.h"
#include <map>
#ifndef _GRADABLE_H_
#define _GRADABLE_H_


/**
 * @class	Gradable 
 *
 * @brief	A gradable object is an object which can be graded using it's own specific grading
 * method which recives specific parmaeters and knows which to use
 */

class Gradable
{
public:

	/**
	 * @fn	virtual double Gradable::evaluateMyGrade (const std::map<std::string, GradingCategory*>&
	 * graders, const std::string& targetString) = 0;
	 *
	 * @brief	Evaluate my grade.
	 *
	 * @param	graders			The graders.
	 * @param	targetString	Target std::string.
	 *
	 * @return	A double.
	 */

	virtual double evaluateMyGrade
			(const std::map<std::string, GradingCategory*>& graders, const std::string& targetString
			 ) = 0;

	/**
	 * @fn	Gradable::Gradable()
	 *
	 * @brief	Default constructor.
	 */

//	Gradable::Gradable() {};

};

#endif // !_GRADABLE_H_

