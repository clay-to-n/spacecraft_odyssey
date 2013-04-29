#ifndef HEALTH_H
#define HEALTH_H

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
  This class contains all data necessary to manage the Health displayed on the screen.
  */
class Health : public Thing
{

  public:
    Health    (QPixmap &pixmap, GameWindow *parent, QGraphicsScene *scene);
    ~Health    ();
    void setNum(int num);

  private:
    QGraphicsScene *scene_;
    GameWindow *parent_;

  public slots:
    void move();
};

#endif // HEALTH_H