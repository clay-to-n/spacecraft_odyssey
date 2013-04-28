#include "thing.h"
#include "gamewindow.h"

/** Default constructor.  Creates a Thing with the specified parameters.
* @param width The width of the tile
* @param height The height of the tile
* @param x The x-position of the tile
* @param y The y-position of the tile
* @param num The number displayed on the tile
* @param parent The GameWindow object which created this Thing
*/
//Thing::Thing(int width, int height, int x, int y, GameWindow *parent) :
    //QGraphicsPixmapItem(x, y, width, height) {

Thing::Thing(QPixmap & pixmap, int x, int y) : QGraphicsPixmapItem(pixmap)
{ 
    x_ = x;
    y_ = y;
    setPos(x_, y_);
    cooldown = 0;
}

/** Destructor */
Thing::~Thing()
{

}

/** Implementation of mousePressEvent to move the tile.
* @param e Standard mouse click pointer implementation
*/



void Thing::move()
{

}