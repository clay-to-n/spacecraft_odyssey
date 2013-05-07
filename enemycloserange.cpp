#include "enemycloserange.h"
#include "gamewindow.h"

/** Default constructor.  Creates an EnemyCloseRange with the specified parameters.
* @param pixmap The Pixmap to display this object with
* @param parent The GameWindow which created this object
* @param scene The scene in which this object exists
*/
EnemyCloseRange::EnemyCloseRange(QPixmap & pixmap, GameWindow * parent, QGraphicsScene *scene) : Thing(pixmap, 0, 0)
{ 
    shoots = false;
    offscreen = false;
    srand(time(NULL));
    scene_ = scene;
    parent_ = parent;
    vy_ = 2;
    x_ = (rand() % 420 + 2);
    y_ = -50;
    setZValue(5);
    health_ = 1;
    score = 20;
    setPos(x_, y_);
    cooldown = 0;
}

/** Destructor */
EnemyCloseRange::~EnemyCloseRange()
{

}

/** Moves the EnemyCloseRange according to it's y-velocity */
void EnemyCloseRange::move()
{
    cooldown++;
    y_ += vy_;
    x_ += vx_;
    if (y_ > parent_->ySize_ )
        offscreen = true;
    setPos(x_, y_);
}