#include "healthitem.h"
#include "gamewindow.h"

/** Default constructor.  Creates a HealthItem with the specified parameters.
* @param width The width of the tile
* @param height The height of the tile
* @param x The x-position of the tile
* @param y The y-position of the tile
* @param num The number displayed on the tile
* @param parent The GameWindow object which created this HealthItem
*/
//HealthItem::HealthItem(int width, int height, int x, int y, GameWindow *parent) :
    //QGraphicsPixmapItem(x, y, width, height) {

HealthItem::HealthItem(QPixmap & pixmap, GameWindow * parent, QGraphicsScene *scene) : Thing(pixmap, 0, 0)
{ 
    shoots = false;
    offscreen = false;
    scene_ = scene;
    parent_ = parent;
    srand(time(NULL));
    x_ = (rand() % 420 + 2);
    vy_ = 1;
    vx_ = 0;
    health_ = 1;
    setZValue(4);
    setPos(x_,0);
    score = 30;
}

/** Destructor */
HealthItem::~HealthItem()
{

}

/** Implementation of mousePressEvent to move the tile.
* @param e Standard mouse click pointer implementation
*/
void HealthItem::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    //parent_->moveTile(this);
}

void HealthItem::setIntPos(int x, int y)
{
    x_ = x;
    y_ = y;
    setPos(x_, y_);

}

/** Moves the HealthItem by updating it's position and calling rectangle's moveTo function.
* @param x The x distance to move
* @param y The y distance to move
*/
void HealthItem::move()
{
    y_ += vy_;
    x_ += vx_;

    if (y_ > parent_->ySize_ )
        offscreen = true;
    if (x_ > parent_->xSize_ )
        offscreen = true;
    if (x_ < -10 )
        offscreen = true;

    setPos(x_, y_);
}