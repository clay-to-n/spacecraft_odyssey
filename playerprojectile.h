#ifndef PLAYERPROJECTILE_H
#define PLAYERPROJECTILE_H

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
  This class contains all data necessary to manage the player's Projectile objects.
  */
class PlayerProjectile : public Thing
{

  public:
    PlayerProjectile(QPixmap &pixmap, GameWindow *parent, QGraphicsScene *scene);
    ~PlayerProjectile();
    void setIntPos(int x, int y);

  private:
    QGraphicsScene *scene_;
    GameWindow *parent_;

  public slots:
    void move();
};

#endif // PLAYERPROJECTILE_H