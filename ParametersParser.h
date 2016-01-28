#pragma once

#include <map>
#include <fstream>
#include "GradingCatagory.h"

#ifndef _PARAMETERS_PARSER_H_
#define _PARAMETERS_PARSER_H_



/**
 * @class	ParametersParser ParametersParser.h ParametersParser.h
 *
 * @brief	The parameters parser.
 */

class ParametersParser final
{
private:
	/** @brief	The parameter parser instance. */
	static ParametersParser* s_parameterParserInstance;

public:

	/**
	 * @fn	static ParametersParser* final::getInstance();
	 *
	 * @brief	Gets the instance.
	 *
	 * @return	null if it fails, else the instance.
	 */

	static ParametersParser* getInstance();

	/**
	 * @fn	static std::map<std::string, GradingCategory*> final::_parseParameterFile(std::ifstream&
	 * sourceFile);
	 *
	 * @brief	Parse parameter file.
	 *
	 * @param [in,out]	sourceFile	Source file.
	 *
	 * @return	a std::map which hold s the type of the grader and the grader itself;
	 */

	static std::map<std::string, GradingCategory*> _parseParameterFile(std::ifstream& sourceFile);


	/**
	 * @fn	static void final::destructor();
	 *
	 * @brief	Destructors this instance.
	 */
	static void destructor();

	/**
	 * @fn	static extractBpmWordList
	 *
	 * @brief	extracts the known bpm word list from the parameter file
	 */
	static std::map<std::string, std::pair<double, double>> extractBpmWordList(std::ifstream&
																			   sourceFile,
																			   std::string& line);
};

#endif // !_PARAMETERS_PARSER_H_

