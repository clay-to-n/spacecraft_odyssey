#include "scoreentry.h"

/** Default constructor.  Creates a ScoreEntry with the specified parameters.
* @param name The name of the player
* @param score The score of the player to display
*/
ScoreEntry::ScoreEntry(QString name, int score)
{ 
    name_ = name;
    score_ = score;
}

/** Destructor */
ScoreEntry::~ScoreEntry()
{

}

int ScoreEntry::getScore()
{
	return score_;
}

QString ScoreEntry::getName()
{
	return name_;
}

bool ScoreEntry::operator<(const ScoreEntry& r)
{
	return (score_ < r.score_);
}

bool ScoreEntry::operator>(const ScoreEntry& r)
{
	return (score_ > r.score_);
}

bool ScoreEntry::operator==(const ScoreEntry& r)
{
	return (score_ == r.score_);
}