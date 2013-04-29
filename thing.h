#ifndef THING_H
#define THING_H

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
#include <time.h>

class GameWindow;
/** This class maintains the image, location, size, and speed of any object in the game.  All other objects to display on-screen will inherit from it.*/
class Thing : public QGraphicsPixmapItem 
{

  public:
    Thing(QPixmap &pixmap, int x, int y);
    ~Thing();
    virtual void move() = 0;    
    bool offscreen;
    bool shoots;
    int cooldown;
    int level;
    int health_;
    int score;

  protected:
    QGraphicsScene *scene_;
    GameWindow *parent_;
    double vx_;
    double vy_;
    int x_;
    int y_;
    
};

#endif // THING_H