#ifndef ENEMYCLOSERANGE_H
#define ENEMYCLOSERANGE_H

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
  This class contains all data necessary to manage EnemyCloseRange objects.
*/
class EnemyCloseRange : public Thing
{

  public:
    EnemyCloseRange(QPixmap &pixmap, GameWindow *parent, QGraphicsScene *scene);
    ~EnemyCloseRange();

  private:
    QGraphicsScene *scene_;
    GameWindow *parent_;

  public slots:
    void move();
};

#endif // ENEMYCLOSERANGE_H