#pragma once
#include <set>
#include "Song.h"

#ifndef _VOCAL_SONG_H_
#define _VOCAL_SONG_H_

/**
 * @class	VocalSong vocalSong.h vocalSong.h
 *
 * @brief	A vocal song.
 */

class VocalSong : public Song
{
public:

	/**
	 * @fn	void VocalSong::printSongSpecialTags() override;
	 *
	 * @brief	Print song special tags.
	 */

	void printSongSpecialTags() override;

	/**
	 * @fn	virtual double VocalSong::evaluateMyGrade (const std::map<std::string, GradingCategory*>
	 * & graders, const std::string& targetString) override;
	 *
	 * @brief	Evaluate song ranking using the graders loaded with the parmaters from the parameter
	 * files
	 *
	 * @param	graders			The diffrent graders.
	 * @param	targetString	query word.
	 *
	 * @return	A double.
	 */

	virtual double evaluateMyGrade
			(const std::map<std::string, GradingCategory*>& graders, const std::string& targetString)
			 override;

	/**
	 * @fn	virtual VocalSong::~VocalSong();
	 *
	 * @brief	Destructor.
	 */

	virtual ~VocalSong();

	/**
	 * @fn	VocalSong::VocalSong(const std::string& songTitle, const std::unordered_map<std::string,
	 * unsigned>& songTags, std::multiset<std::string>& sourceSongLyrics, const std::string&
	 * sourceSongWriter);
	 *
	 * @brief	Constructor.
	 *
	 * @param	songTitle					The song title.
	 * @param	songTags					The song tags.
	 * @param [in,out]	sourceSongLyrics	Source song lyrics.
	 * @param	sourceSongWriter			Source song writer.
	 */

	VocalSong(const std::string& songTitle, const std::unordered_map<std::string, unsigned>& songTags,
			  std::multiset<std::string>& sourceSongLyrics, const std::string& sourceSongWriter);

	/**
	 * @fn	const std::multiset<std::string>& VocalSong::getLyrics() const;
	 *
	 * @brief	Gets the lyrics.
	 *
	 * @return	The lyrics.
	 */

	const std::multiset<std::string>& getLyrics() const;

	/**
	 * @fn	const std::string& VocalSong::getSongWriter() const;
	 *
	 * @brief	Gets song writer.
	 *
	 * @return	The song writer.
	 */

	const std::string& getSongWriter() const;

private:
	/** @brief	holds The lyrics. */
	std::multiset<std::string> _lyrics;
	/** @brief	holds The song writer. */
	std::string _songWriter;
};

#endif
