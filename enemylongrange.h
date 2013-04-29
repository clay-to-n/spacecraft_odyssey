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
  This class contains all data necessary to manage long-range enemy objects.
*/
class EnemyLongRange : public Thing
{

  public:
    EnemyLongRange(QPixmap &pixmap, GameWindow *parent, QGraphicsScene *scene);
    ~EnemyLongRange();

  private:
    QGraphicsScene *scene_;
    GameWindow *parent_;
    /** This is the maximum distance from the top of the screen that this enemy will travel */
    int yBarrier;

  public slots:
    void move();
};

#endif // ENEMYLONGRANGE_H