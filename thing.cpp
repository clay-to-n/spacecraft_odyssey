#include "thing.h"
#include "gamewindow.h"

/** Default constructor.  Creates a Thing with the specified parameters.
* @param pixmap The Pixmap to display this object with
* @param x The x location to place the thing
* @param y The y location to place the thing
*/
Thing::Thing(QPixmap & pixmap, int x, int y) : QGraphicsPixmapItem(pixmap)
{ 
    x_ = x;
    y_ = y;
    setPos(x_, y_);
    cooldown = 0;
    level = 0;
    score = 0;
}

/** Destructor */
Thing::~Thing()
{

}