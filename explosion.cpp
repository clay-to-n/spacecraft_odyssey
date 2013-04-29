#include "explosion.h"
#include "gamewindow.h"

/** Default constructor.  Creates an Explosion with the specified parameters.
* @param pixmap The Pixmap to display this object with
* @param parent The GameWindow which created this object
* @param scene The scene in which this object exists
*/
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

/** This function increases the explosions health and lets the object calling it know that it is a "lingering" secondary explosion. */
void Explosion::makeLinger()
{
    health_ = 12;
    linger = true;
}

/** Sets the position of the Explosion as well as updating the x_ and y_ data members to reflect this.
* @param x The x position to use
* @param y The y position to use
*/
void Explosion::setIntPos(int x, int y)
{
    x_ = x;
    y_ = y;
    setPos(x_, y_);
}

/** The move function for explosions is actually a simple way of decreasing their health - so that they last for a specified period of time before reaching zero health (at which time the gamewindow will delete them automatically)
*/
void Explosion::move()
{
    health_ --;
    setPos(x_, y_);
}