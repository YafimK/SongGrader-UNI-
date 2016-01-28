/**
 * @file	InstrumentalSong.cpp
 *
 * @brief	Implements the instrumental song class.
 */

#include <iostream>
#include "InstrumentalSong.h"
#include "InstrumentsMatchGrader.h"
#include "BpmGradingCatagory.h"



void InstrumentalSong::printSongSpecialTags()
{
	std::cout << PERFORMED_BY_TAG << this->getPerfomers();
}


double InstrumentalSong::evaluateMyGrade(const std::map<std::string, GradingCategory*>& graders,
										 const std::string& targetString)
{
	double matchScore = Song::evaluateMyGrade(graders, targetString);

	InstrumentsMatchGrader instrumentsMatchGrader =
			*dynamic_cast<InstrumentsMatchGrader*>(graders.at(INSTRUMENTS_MATCH));
	matchScore += instrumentsMatchGrader.catagoryGrader(this->getInstruments(), targetString);

	if(DEFAULT_BPM != this->getSongBpm())
	{
		BpmGradingCatagory
				bpmMatchGrader = *dynamic_cast<BpmGradingCatagory*>(graders.at(BPM_MATCH));
		matchScore += bpmMatchGrader.catagoryGrader(this->getSongBpm(), targetString);
	}

	return matchScore;
}


InstrumentalSong::InstrumentalSong(const std::string& songTitle, const std::unordered_map<std::
								   string, unsigned>& songTags, const std::multiset<std::string>&
								   songInstruments, const std::string& songPerformers, const double&
								   songBpm):Song(songTitle, songTags)
{
	this->_instruments = songInstruments;
	this->_perfomers = songPerformers;
	this->_songBpm = songBpm;
}


InstrumentalSong::InstrumentalSong(const std::string& songTitle,
								   const std::unordered_map<std::string, unsigned>& songTags, const
                                   std::multiset<std::string>& songInstruments, const std::string&
								   songPerformers):InstrumentalSong(songTitle, songTags,
								   songInstruments, songPerformers, DEFAULT_BPM)
{
}



const std::multiset<std::string>& InstrumentalSong::getInstruments() const
{
	return _instruments;
}


const std::string& InstrumentalSong::getPerfomers() const
{
	return _perfomers;
}



const double& InstrumentalSong::getSongBpm() const
{
	return _songBpm;
}
