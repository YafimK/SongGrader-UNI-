#pragma once

#include <unordered_map>
#include <vector>
#include "Song.h"

#ifndef _SONG_PARSER_H_
#define _SONG_PARSER_H_

/**
 * @def	LEFT_VALUE_BRACKT();
 *
 * @brief	A macro that defines left and right values in the file
 */

#define LEFT_VALUE_BRACKT '{'
#define RIGHT_VALUE_BRACKT '}'

static const int LAST_SONG_TRUE_FLAG = 1;
static const int LAST_SONG_FALSE_FLAG = 0;



/**
 * @class	SongParser SongParser.h SongParser.h
 *
 * @brief	the song file parser
 */

class SongParser final
{
private:


	/**
	 * @fn	static std::unordered_map<std::string, unsigned int> final::_tagReader(const std::vector<std::string>& readWordsList);
	 *
	 * @brief	turns the word list to a std::map of each tag and it's value
	 *
	 * @param	readWordsList	List of read words.
	 *
	 * @return	An std::unordered_map&lt;std::string,unsigned int&gt;
	 */

	static std::unordered_map<std::string, unsigned int> _tagReader(const std::vector<std::string>& readWordsList);

	/**
	 * @fn	static std::vector<std::string> final::_getWordsList(const std::string& readLine);
	 *
	 * @brief	reads the line and tokenizes to a nice list
	 *
	 * @param	readLine	The read line.
	 *
	 * @return	The words list.
	 */

	static std::vector<std::string> _getWordsList(const std::string& readLine);
	/** @brief	The song parser instance. */
	static SongParser* s_songParserInstance;

public:
//

	/**
	 * @fn	static bool final::isVocalSong(std::string& line);
	 *
	 * @brief	Is vocal song.
	 *
	 * @param [in,out]	line	The line.
	 *
	 * @return	true if vocal song, false if not.
	 */

	static bool isVocalSong(std::string& line);

	/**
	 * @fn	static std::vector<Song*> final::parseSong(std::ifstream& sourceFile);
	 *
	 * @brief	parses the song file and returns a std::vector that is a collection of songs
	 *
	 * @param [in,out]	sourceFile	Source file.
	 *
	 * @return	null if it fails, else a std::vector&lt;Song*&gt;
	 */

	static std::vector<Song*> parseSong(std::ifstream& sourceFile);

	/**
	 * @fn	static SongParser* final::initillizer();
	 *
	 * @brief	initillizes the singelton
	 *
	 * @return	null if it fails, else a SongParser*.
	 */

	static SongParser* initillizer();

	/**
	 * @fn	static void final::songParserDestructor();
	 *
	 * @brief	Song parser destructor.
	 */

	static void songParserDestructor();
};

#endif
