#pragma once

#include <set>
#include "Song.h"

#ifndef _INSTRUMENTAL_SONG_H_
#define _INSTRUMENTAL_SONG_H_

#define PERFORMED_BY_TAG "performed by: "

const static double DEFAULT_BPM = - 1.00;

/**
 * @class	InstrumentalSong InstrumentalSong.h InstrumentalSong.h
 *
 * @brief	An instrumental song.
 */

class InstrumentalSong : public Song
{
public:

	/**
	 * @fn	void InstrumentalSong::printSongSpecialTags() override;
	 *
	 * @brief	Print song special tags - preformed by
	 */

	void printSongSpecialTags() override;

	/**
	 * @fn	virtual double InstrumentalSong::evaluateMyGrade (const std::map<std::string,
	 * GradingCategory*>& graders, const std::string& targetString) override;
	 *
	 * @brief	Evaluate the score of the song using the specified graders needed and depends on the
	 * queryword
	 *
	 * @param	graders			The graders.
	 * @param	targetString	Target std::string.
	 *
	 * @return	A double.
	 */

	virtual double evaluateMyGrade
			(const std::map<std::string, GradingCategory*>& graders, const std::string& targetString)
			 override;

	/**
	 * @fn	InstrumentalSong::InstrumentalSong(const std::string& songTitle, const std::
	 * unordered_map<std::string, unsigned>& songTags, const std::multiset<std::string>&
	 * songInstruments, const std::string& songPerformers, const double& songBpm);
	 *
	 * @brief	Constructor.
	 *
	 * @param	songTitle	   	The song title.
	 * @param	songTags	   	The song tags.
	 * @param	songInstruments	The song instruments.
	 * @param	songPerformers 	The song performers.
	 * @param	songBpm		   	The song bpm.
	 */

	InstrumentalSong(const std::string& songTitle, const std::unordered_map<std::string, unsigned>&
					 songTags, const std::multiset<std::string>& songInstruments, const std::string&
					 songPerformers, const double& songBpm);

	/**
	 * @fn	InstrumentalSong::InstrumentalSong(const std::string& songTitle, const std::
	 * unordered_map<std::string, unsigned>& songTags, const std::multiset<std::string>&
	 * songInstruments, const std::string& songPerformers);
	 *
	 * @brief	Constructor.
	 *
	 * @param	songTitle	   	The song title.
	 * @param	songTags	   	The song tags.
	 * @param	songInstruments	The song instruments.
	 * @param	songPerformers 	The song performers.
	 */

	InstrumentalSong(const std::string& songTitle, const std::unordered_map<std::string, unsigned>&
					 songTags, const std::multiset<std::string>& songInstruments, const std::string&
					 songPerformers);

	/**
	 * @fn	const std::multiset<std::string>& InstrumentalSong::getInstruments() const;
	 *
	 * @brief	return the instruments collection
	 *
	 * @return	The instruments.
	 */

	const std::multiset<std::string>& getInstruments() const;

	/**
	 * @fn	const std::string& InstrumentalSong::getPerfomers() const;
	 *
	 * @brief	Gets the perfomers.
	 *
	 * @return	The perfomers.
	 */

	const std::string& getPerfomers() const;

	/**
	 * @fn	const double& InstrumentalSong::getSongBpm() const;
	 *
	 * @brief	Gets song bpm.
	 *
	 * @return	The song bpm.
	 */

	const double& getSongBpm() const;

private:
	/** @brief	The instruments. */
	std::multiset<std::string> _instruments;
	/** @brief	The perfomers. */
	std::string _perfomers;
	/** @brief	The song bpm. */
	double _songBpm;
};

#endif
