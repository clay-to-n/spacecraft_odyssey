#ifndef SCROLLINGBACKGROUND_H
#define SCROLLINGBACKGROUND_H

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
#include "thing.h"



class GameWindow;
/**
  This class maintains the location, size, and speed of a QGraphicsRectItem.
  It is easier to do the arithmetic with this data, and then update the position
  separately, then to extract coordinates from the QRectF that is contained within
  the QGraphicsRectItem
  */
class ScrollingBackground : public Thing
{

  public:
    ScrollingBackground(QPixmap &pixmap, GameWindow *parent, QGraphicsScene *scene);
    ~ScrollingBackground();

  private:
    QGraphicsScene *scene_;
    GameWindow *parent_;



  public slots:
    void move();
};

#endif // SCROLLINGBACKGROUND_H