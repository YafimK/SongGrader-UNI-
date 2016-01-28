#pragma once

#include <vector>
#include "Song.h"

#ifndef _SONG_GRADER_H_
#define _SONG_GRADER_H_

#define RESULT_SEPRATOR "----------------------------------------"

#define QUERY_WORD_LABEL "Query word: "
#define TAGS_SEPRATOR "\t"


/**
 * @class	SongGrader SongGrader.h SongGrader.h
 *
 * @brief	the song grader class which parses the query words and runts the grading process for each song per query word and then printing them
 */

class SongGrader
{
public:

	/**
	 * @fn	virtual SongGrader::~SongGrader()
	 *
	 * @brief	Destructor.
	 */

	virtual ~SongGrader() {	};

	/**
	 * @fn	static SongGrader* SongGrader::getSongGraderInstance();
	 *
	 * @brief	Gets song grader instance.
	 *
	 * @return	null if it fails, else the song grader instance.
	 */

	static SongGrader* getSongGraderInstance();

	/**
	 * @fn	static const std::vector<std::string>& SongGrader::s_getQueryWordsCollection();
	 *
	 * @brief	Gets query words collection.
	 *
	 * @return	The query words collection.
	 */

	static const std::vector<std::string>& getQueryWordsCollection();

	/**
	 * @fn	static void SongGrader::parseQueryFile(std::ifstream& sourceFile);
	 *
	 * @brief	Parse query file.
	 *
	 * @param [in,out]	sourceFile	Source file.
	 */

	static void parseQueryFile(std::ifstream& sourceFile);

	/**
	 * @fn	static void SongGrader::runGrading(std::vector<Song*>& rankedSongs, std::map<std::string, GradingCategory*>& gradingTools);
	 *
	 * @brief	Executes the grading operation.
	 *
	 * @param [in,out]	rankedSongs 	[in,out] If non-null, the ranked songs.
	 * @param [in,out]	gradingTools	[in,out] If non-null, the grading tools.
	 */

	static void
			runGrading(std::vector<Song*>& rankedSongs, std::map<std::string, GradingCategory*>& gradingTools);

	/**
	 * @fn	static void SongGrader::_songGraderDestructor();
	 *
	 * @brief	Song grader destructor.
	 */

	static void _songGraderDestructor();

	/**
	 * @fn	static void SongGrader::_printSongRanking(std::vector<std::pair<Song*, double>>& rankedSong, std::string& queryWord);
	 *
	 * @brief	Print song ranking.
	 *
	 * @param [in,out]	rankedSong	[in,out] If non-null, the ranked song.
	 * @param [in,out]	queryWord 	The query word.
	 */

	static void _printSongRanking(std::vector<std::pair<Song*, double>>& rankedSong, std::string& queryWord);

private:

	/**
	 * @fn	static bool SongGrader::_compareSongRank(std::pair<Song*, double> firstSong, std::pair<Song*, double> secondSong);
	 *
	 * @brief	Compare song by ranks
	 *
	 * @param [in,out]	firstSong 	If non-null, the first song.
	 * @param [in,out]	secondSong	If non-null, the second song.
	 *
	 * @return	true if it succeeds, false if it fails.
	 */

	static bool _compareSongRank(std::pair<Song*, double> firstSong, std::pair<Song*, double> secondSong);

	/**
	 * @fn	SongGrader::SongGrader()
	 *
	 * @brief	Default constructor.
	 */

	SongGrader() {};
	/** @brief	The song grader instance. */
	static SongGrader* s_songGraderInstance;
	/** @brief	Collection of query words. */
	static std::vector<std::string> s_queryWordCollection;
};

#endif // !_SONG_GRADER_H_

