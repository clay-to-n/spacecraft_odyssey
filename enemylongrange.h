#ifndef ENEMYLONGRANGE_H
#define ENEMYLONGRANGE_H

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
/**
  This class maintains the location, size, and speed of a QGraphicsRectItem.
  It is easier to do the arithmetic with this data, and then update the position
  separately, then to extract coordinates from the QRectF that is contained within
  the QGraphicsRectItem
  */
class EnemyLongRange : public Thing
{

  public:
    EnemyLongRange(QPixmap &pixmap, GameWindow *parent, QGraphicsScene *scene);
    ~EnemyLongRange();
    void mousePressEvent(QGraphicsSceneMouseEvent *e);

  private:
    QGraphicsScene *scene_;
    GameWindow *parent_;
    int yBarrier;



  public slots:
    void move();
};

#endif // ENEMYLONGRANGE_H