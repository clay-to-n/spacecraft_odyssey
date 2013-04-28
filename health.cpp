#include "health.h"
#include "gamewindow.h"

/** Default constructor.  Creates a Health with the specified parameters.
* @param width The width of the tile
* @param height The height of the tile
* @param x The x-position of the tile
* @param y The y-position of the tile
* @param num The number displayed on the tile
* @param parent The GameWindow object which created this Health
*/
//Health::Health(int width, int height, int x, int y, GameWindow *parent) :
    //QGraphicsPixmapItem(x, y, width, height) {

Health::Health(QPixmap & pixmap, GameWindow * parent, QGraphicsScene *scene) : Thing(pixmap, 0, 0)
{ 
    offscreen = false;
    scene_ = scene;
    parent_ = parent;
    vy_ = 0; 
    vx_ = 0;
    x_ = 20;
    y_ = 530;
    setPos(x_, y_);
    setZValue(10);
}

/** Destructor */
Health::~Health()
{

}

/** Implementation of mousePressEvent to move the tile.
* @param e Standard mouse click pointer implementation
*/

void Health::setNum(int num)
{
    x_ += 29*num;
    setPos(x_, y_);
}
/** Moves the Health by updating it's position and calling rectangle's moveTo function.
* @param x The x distance to move
* @param y The y distance to move
*/
void Health::move()
{
    
}