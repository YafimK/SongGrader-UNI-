#pragma once

#include <string>
#include <unordered_map>
#include "Gradable.h"

#define DEFAULT_STRING ""

#ifndef _SONG_H_
#define _SONG_H_



/**
 * @class	Song Song.h Song.h
 *
 * @brief	A basic song.
 */

class Song : public Gradable
{
public:

	/**
	 * @fn	virtual Song::~Song() = default;
	 *
	 * @brief	Destructor.
	 */

	virtual ~Song() = default;

	/**
	 * @fn	virtual double Song::evaluateMyGrade (const std::map<std::string, GradingCategory*>& graders, const std::string& targetString) override;
	 *
	 * @brief	Evaluate the song rank
	 *
	 * @param	graders			The graders.
	 * @param	targetString	Target std::string.
	 *
	 * @return	A double.
	 */

	virtual double evaluateMyGrade
			(const std::map<std::string, GradingCategory*>& graders, const std::string& targetString) override;

	/**
	 * @fn	Song::Song(const std::string& songTitle, const std::unordered_map<std::string, unsigned>& sourceSongTags);
	 *
	 * @brief	Constructor.
	 *
	 * @param	songTitle	  	The song title.
	 * @param	sourceSongTags	Source song tags.
	 */

	Song(const std::string& songTitle, const std::unordered_map<std::string, unsigned>& sourceSongTags);

	/**
	 * @fn	std::unordered_map<std::string, unsigned>& Song::getSongTags();
	 *
	 * @brief	Gets song tags.
	 *
	 * @return	The song tags.
	 */

	std::unordered_map<std::string, unsigned>& getSongTags();

	/**
	 * @fn	const std::string& Song::getSongTitle() const;
	 *
	 * @brief	Gets song title.
	 *
	 * @return	The song title.
	 */

	const std::string& getSongTitle() const;

	/**
	 * @fn	virtual void Song::printSongSpecialTags() = 0;
	 *
	 * @brief	Print song special tags.
	 */

	virtual void printSongSpecialTags() = 0;

private:
	/** @brief	The song title. */
	std::string _title;
	/** @brief	The song tags. */
	std::unordered_map<std::string, unsigned int> _songTags;
};

#endif
