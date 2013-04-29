#ifndef EXPLOSION_H
#define EXPLOSION_H

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
  This class contains all data necessary to manage explosion objects, which will be created when collisions occur and destroyed soon after.
  */
class Explosion : public Thing
{

  public:
    Explosion(QPixmap &pixmap, GameWindow *parent, QGraphicsScene *scene);
    ~Explosion();
    void setIntPos(int x, int y);
    void makeLinger();
    bool linger;

  private:
    QGraphicsScene *scene_;
    GameWindow *parent_;


  public slots:
    void move();
};

#endif // EXPLOSION_H