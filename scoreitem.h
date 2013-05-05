#ifndef SCOREITEM_H
#define SCOREITEM_H

#include <QtGui/QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QListView>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsSceneMouseEvent>
#include "thing.h"

class GameWindow;

/** This class contains all data necessary to manage ScoreItem objects.*/
class ScoreItem : public Thing
{

  public:
    ScoreItem(QPixmap &pixmap, GameWindow *parent, QGraphicsScene *scene);
    ~ScoreItem();
    void setIntPos(int x, int y);
    int random;

  private:
    QGraphicsScene *scene_;
    GameWindow *parent_;



  public slots:
    void move();
};

#endif // SCOREITEM_H