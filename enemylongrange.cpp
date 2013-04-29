#include "enemylongrange.h"
#include "gamewindow.h"

/** Default constructor.  Creates a Long Range Enemy with the specified parameters.
* @param pixmap The Pixmap to display this object with
* @param parent The GameWindow which created this object
* @param scene The scene in which this object exists
*/
EnemyLongRange::EnemyLongRange(QPixmap & pixmap, GameWindow * parent, QGraphicsScene *scene) : Thing(pixmap, 0, 0)
{ 
    shoots = true;
    offscreen = false;
    srand(time(NULL));
    scene_ = scene;
    parent_ = parent;
    cooldown = (200 + rand() % 190);
    vy_ = 1;
    x_ = (rand() % 420 + 2);
    vx_ = (-2 + (rand() % 5));
    y_ = -50;
    setPos(x_, y_);
    setZValue(5);
    yBarrier = ((rand() % 100) + 200);
    health_ = 2;
    score = 50;
}

/** Destructor */
EnemyLongRange::~EnemyLongRange()
{

}

/** Moves the EnemyLongRange according to it's current velocities and the randomly generated yBarrier.
*/
void EnemyLongRange::move()
{
    
    if (y_ > parent_->ySize_ )
        offscreen = true;
    if (y_ > yBarrier && vy_ > 0)
    {
        vy_ = -vy_;
        if (vx_ == 0)
            vx_ = -1;
        if (vx_ == -2)
            vx_ ++;
        if (vx_ == 2)
            vx_ --;
    }
    if ( vy_ < 0 && y_ < -40)
    {
        vy_ = -vy_;
        if (vx_ == 1)
            vx_ ++;
        if (vx_ == -1)
            vx_ --;
    }
    if (x_ < 0 || x_ > (parent_->xSize_ - pixmap().width()))
        vx_ = -vx_;

    y_ += vy_;
    x_ += vx_;
    setPos(x_, y_);
}