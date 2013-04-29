#include "health.h"
#include "gamewindow.h"

/** Default constructor.  Creates a Health indicator with the specified parameters.
* @param pixmap The Pixmap to display this object with
* @param parent The GameWindow which created this object
* @param scene The scene in which this object exists
*/
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

/**Sets the position of this object based on how many health indicators there already are */
void Health::setNum(int num)
{
    x_ += 29*num;
    setPos(x_, y_);
}

/**Unused move function */
void Health::move()
{
    
}