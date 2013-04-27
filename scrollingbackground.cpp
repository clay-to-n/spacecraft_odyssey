#include "scrollingbackground.h"
#include "gamewindow.h"

/** Default constructor.  Creates a ScrollingBackground with the specified parameters.
* @param width The width of the tile
* @param height The height of the tile
* @param x The x-position of the tile
* @param y The y-position of the tile
* @param num The number displayed on the tile
* @param parent The GameWindow object which created this ScrollingBackground
*/
//ScrollingBackground::ScrollingBackground(int width, int height, int x, int y, GameWindow *parent) :
    //QGraphicsPixmapItem(x, y, width, height) {

ScrollingBackground::ScrollingBackground(QPixmap & pixmap, GameWindow * parent, QGraphicsScene *scene) : Thing(pixmap, 0, 0)
{ 
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

/** Implementation of mousePressEvent to move the tile.
* @param e Standard mouse click pointer implementation
*/

void ScrollingBackground::setIntPos(int x, int y)
{
    x_ = x;
    y_ = y;
    setPos(x_, y_);
}
/** Moves the ScrollingBackground by updating it's position and calling rectangle's moveTo function.
* @param x The x distance to move
* @param y The y distance to move
*/
void ScrollingBackground::move()
{
    y_ += vy_;
    setPos(x_, y_);
}