#ifndef ENEMYPROJECTILE_H
#define ENEMYPROJECTILE_H

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
  This class contains all data necessary to manage enemy projectile objects.
*/
class EnemyProjectile : public Thing
{

  public:
    EnemyProjectile(QPixmap &pixmap, GameWindow *parent, QGraphicsScene *scene);
    ~EnemyProjectile();
    void setIntPos(int x, int y);
    void setVelocity(int vx, int vy);

  private:
    QGraphicsScene *scene_;
    GameWindow *parent_;



  public slots:
    void move();
};

#endif // ENEMYPROJECTILE_H