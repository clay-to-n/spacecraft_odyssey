#include "enemylongrange.h"
#include "gamewindow.h"

/** Default constructor.  Creates a EnemyLongRange with the specified parameters.
* @param width The width of the tile
* @param height The height of the tile
* @param x The x-position of the tile
* @param y The y-position of the tile
* @param num The number displayed on the tile
* @param parent The GameWindow object which created this EnemyLongRange
*/
//EnemyLongRange::EnemyLongRange(int width, int height, int x, int y, GameWindow *parent) :
    //QGraphicsPixmapItem(x, y, width, height) {

EnemyLongRange::EnemyLongRange(QPixmap & pixmap, GameWindow * parent, QGraphicsScene *scene) : Thing(pixmap, 0, 0)
{ 
    offscreen = false;
    srand(time(NULL));
    scene_ = scene;
    parent_ = parent;
    vy_ = 1;
    x_ = (rand() % 420 + 2);
    vx_ = (-2 + (rand() % 5));
    y_ = -50;
    setPos(x_, y_);
    setZValue(5);
    yBarrier = ((rand() % 100) + 200);
    health_ = 2;
}

/** Destructor */
EnemyLongRange::~EnemyLongRange()
{

}

/** Implementation of mousePressEvent to move the tile.
* @param e Standard mouse click pointer implementation
*/
void EnemyLongRange::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    //parent_->moveTile(this);
}

/** Moves the EnemyLongRange by updating it's position and calling rectangle's moveTo function.
* @param x The x distance to move
* @param y The y distance to move
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
    //else
    y_ += vy_;
    x_ += vx_;
    setPos(x_, y_);
}