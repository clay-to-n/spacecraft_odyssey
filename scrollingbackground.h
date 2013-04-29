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
  This class contains all data necessary to manage scrolling non-interactable background objects.
  */
class ScrollingBackground : public Thing
{

  public:
    ScrollingBackground(QPixmap &pixmap, GameWindow *parent, QGraphicsScene *scene);
    ~ScrollingBackground();
    void setIntPos(int x, int y);

  private:
    QGraphicsScene *scene_;
    GameWindow *parent_;

  public slots:
    void move();
};

#endif // SCROLLINGBACKGROUND_H