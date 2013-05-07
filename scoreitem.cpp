#include "scoreitem.h"
#include "gamewindow.h"

/** Default constructor.  Creates a ScoreItem with the specified parameters.
* @param width The width of the tile
* @param height The height of the tile
* @param x The x-position of the tile
* @param y The y-position of the tile
* @param num The number displayed on the tile
* @param parent The GameWindow object which created this ScoreItem
*/
ScoreItem::ScoreItem(QPixmap & pixmap, GameWindow * parent, QGraphicsScene *scene) : Thing(pixmap, 0, 0)
{ 
    srand(time(NULL)*random);
    shoots = false;
    offscreen = false;
    scene_ = scene;
    parent_ = parent;
    vy_ = rand()%2 - rand()%4;
    vx_ = rand()%2 - rand()%4;
    health_ = 10;
    setZValue(3);
    setPos(0,0);
    score = 5;
    cooldown = 0;
}

/** Destructor */
ScoreItem::~ScoreItem()
{

}

/** Sets the position of the Score Item as well as updating the x_ and y_ data members to reflect this.
* @param x The x position to use
* @param y The y position to use
*/
void ScoreItem::setIntPos(int x, int y)
{
    x_ = x;
    y_ = y;
    setPos(x_, y_);
}

/** Moves the ScoreItem downward */
void ScoreItem::move()
{
    cooldown ++;
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