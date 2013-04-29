#ifndef ENEMYBOSS_H
#define ENEMYBOSS_H

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
  This class contains all data necessary to manage enemy Boss objects.
*/
class EnemyBoss : public Thing
{

  public:
    EnemyBoss(QPixmap &pixmap, GameWindow *parent, QGraphicsScene *scene);
    ~EnemyBoss();
    void setLevel(int levelCount);

  private:
    QGraphicsScene *scene_;
    GameWindow *parent_;
    int yBarrier;
    int barrierTemp;
    int vxDefault;
    int vyDefault;

  public slots:
    void move();
};

#endif // ENEMYBOSS_H