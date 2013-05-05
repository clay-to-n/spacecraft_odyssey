#ifndef SCOREENTRY_H
#define SCOREENTRY_H

#include <QtGui/QMainWindow>
#include <QString>

/**
  This class contains all data necessary to manage names and scores to display in the high score list.
*/
class ScoreEntry
{

  public:
    ScoreEntry(QString name, int score);
    ~ScoreEntry();
    int getScore();
    QString getName();
    
    bool operator<(const ScoreEntry& r);
    bool operator>(const ScoreEntry& r);
    bool operator==(const ScoreEntry& r);

  private:
    QString name_;
    int score_;


};

#endif // SCOREENTRY_H