#include "playerprojectile.h"
#include "gamewindow.h"

/** Default constructor.  Creates a PlayerProjectile with the specified parameters.
* @param pixmap The Pixmap to display this object with
* @param parent The GameWindow which created this object
* @param scene The scene in which this object exists
*/
PlayerProjectile::PlayerProjectile(QPixmap & pixmap, GameWindow * parent, QGraphicsScene *scene) : Thing(pixmap, 0, 0)
{ 
    shoots = false;
    offscreen = false;
    scene_ = scene;
    parent_ = parent;
    vy_ = -6;
    health_ = 1;
    setZValue(4);
    setPos(0,0);
}

/** Destructor */
PlayerProjectile::~PlayerProjectile()
{

}

/** Sets the position of the PlayerProjectile as well as updating the x_ and y_ data members to reflect this.
* @param x The x position to use
* @param y The y position to use
*/
void PlayerProjectile::setIntPos(int x, int y)
{
    x_ = x;
    y_ = y;
    setPos(x_, y_);
}

/** Moves the PlayerProjectile by updating it's position according to it's data members
*/
void PlayerProjectile::move()
{
    y_ += vy_;

    if (y_ < -10)
        offscreen = true;

    setPos(x_, y_);
}