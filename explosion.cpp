#include "explosion.h"
#include "gamewindow.h"

/** Default constructor.  Creates a Explosion with the specified parameters.
* @param width The width of the tile
* @param height The height of the tile
* @param x The x-position of the tile
* @param y The y-position of the tile
* @param num The number displayed on the tile
* @param parent The GameWindow object which created this Explosion
*/
//Explosion::Explosion(int width, int height, int x, int y, GameWindow *parent) :
    //QGraphicsPixmapItem(x, y, width, height) {

Explosion::Explosion(QPixmap & pixmap, GameWindow * parent, QGraphicsScene *scene) : Thing(pixmap, 0, 0)
{ 
    shoots = false;
    offscreen = false;
    scene_ = scene;
    parent_ = parent;
    setZValue(4);
    health_ = 8;
    linger = false;
}

/** Destructor */
Explosion::~Explosion()
{

}

/** Implementation of mousePressEvent to move the tile.
* @param e Standard mouse click pointer implementation
*/
void Explosion::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    //parent_->moveTile(this);
}

void Explosion::makeLinger()
{
    health_ = 12;
    linger = true;
}

void Explosion::setIntPos(int x, int y)
{
    x_ = x;
    y_ = y;
    setPos(x_, y_);

}

/** Moves the Explosion by updating it's position and calling rectangle's moveTo function.
* @param x The x distance to move
* @param y The y distance to move
*/
void Explosion::move()
{
    health_ --;
    setPos(x_, y_);
}