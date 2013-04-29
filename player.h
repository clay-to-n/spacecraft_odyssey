#ifndef PLAYER_H
#define PLAYER_H

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
#include <sstream>
#include "thing.h"

class GameWindow;

/**
  This class contains all data necessary to manage player objects.
*/
class Player : public Thing
{

  public:
    Player(QPixmap &pixmap, GameWindow *parent, QGraphicsScene *scene);
    ~Player();

  private:
    QGraphicsScene *scene_;
    GameWindow *parent_;

  public slots:
    void move();
};

#endif // PLAYER_H