#include "playerprojectile.h"
#include "gamewindow.h"

/** Default constructor.  Creates a PlayerProjectile with the specified parameters.
* @param width The width of the tile
* @param height The height of the tile
* @param x The x-position of the tile
* @param y The y-position of the tile
* @param num The number displayed on the tile
* @param parent The GameWindow object which created this PlayerProjectile
*/
//PlayerProjectile::PlayerProjectile(int width, int height, int x, int y, GameWindow *parent) :
    //QGraphicsPixmapItem(x, y, width, height) {

PlayerProjectile::PlayerProjectile(QPixmap & pixmap, GameWindow * parent, QGraphicsScene *scene) : Thing(pixmap, 0, 0)
{ 
    shoots = false;
    offscreen = false;
    scene_ = scene;
    parent_ = parent;
    vy_ = -6;
    health_ = 3;
    setZValue(4);
    setPos(0,0);
}

/** Destructor */
PlayerProjectile::~PlayerProjectile()
{

}

/** Implementation of mousePressEvent to move the tile.
* @param e Standard mouse click pointer implementation
*/
void PlayerProjectile::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    //parent_->moveTile(this);
}

void PlayerProjectile::setIntPos(int x, int y)
{
    x_ = x;
    y_ = y;
    setPos(x_, y_);

}

/** Moves the PlayerProjectile by updating it's position and calling rectangle's moveTo function.
* @param x The x distance to move
* @param y The y distance to move
*/
void PlayerProjectile::move()
{
    y_ += vy_;

    if (y_ < -10)
        offscreen = true;

    setPos(x_, y_);
}