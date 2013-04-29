#ifndef HEALTHITEM_H
#define HEALTHITEM_H

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

/** This class contains all data necessary to manage HealthItem objects.*/
class HealthItem : public Thing
{

  public:
    HealthItem(QPixmap &pixmap, GameWindow *parent, QGraphicsScene *scene);
    ~HealthItem();
    void setIntPos(int x, int y);

  private:
    QGraphicsScene *scene_;
    GameWindow *parent_;



  public slots:
    void move();
};

#endif // HEALTHITEM_H