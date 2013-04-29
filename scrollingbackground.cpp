#include "scrollingbackground.h"
#include "gamewindow.h"

/** Default constructor.  Creates a ScrollingBackground with the specified parameters.
* @param pixmap The Pixmap to display this object with
* @param parent The GameWindow which created this object
* @param scene The scene in which this object exists
*/
ScrollingBackground::ScrollingBackground(QPixmap & pixmap, GameWindow * parent, QGraphicsScene *scene) : Thing(pixmap, 0, 0)
{ 
    shoots = false;
    offscreen = false;
    scene_ = scene;
    parent_ = parent;
    vy_ = 1; 
    vx_ = 0;
    x_ = 0;
    y_ = -4360;
    setPos(x_, y_);
}

/** Destructor */
ScrollingBackground::~ScrollingBackground()
{

}

/** Sets the position of the Background as well as updating the x_ and y_ data members to reflect this.
* @param x The x position to use
* @param y The y position to use
*/
void ScrollingBackground::setIntPos(int x, int y)
{
    x_ = x;
    y_ = y;
    setPos(x_, y_);
}

/** Moves the ScrollingBackground downward */
void ScrollingBackground::move()
{
    y_ += vy_;
    setPos(x_, y_);
}