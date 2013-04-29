#include "player.h"
#include "gamewindow.h"

/** Default constructor.  Creates a Player with the specified parameters.
* @param pixmap The Pixmap to display this object with
* @param parent The GameWindow which created this object
* @param scene The scene in which this object exists
*/
Player::Player(QPixmap & pixmap, GameWindow * parent, QGraphicsScene *scene) : Thing(pixmap, 0, 0)
{ 
    offscreen = false;
    shoots = false;
    scene_ = scene;
    parent_ = parent;
    x_ = 200;
    y_ = 500;
    setZValue(6);
    setPos(x_, y_);
    health_ = 5;
}

/** Destructor */
Player::~Player()
{

}

/** Moves the Player by updating it's position and calling a set Position function.
*/
void Player::move()
{
    if (parent_->pressedD){
        if ((x_+pixmap().width()+4) < parent_->xSize_)
            x_ += 2;
    }    
    if (parent_->pressedW){
        if (y_ > 4)
            y_ -= 2;
    }
    if (parent_->pressedA){
        if (x_ > 4)
            x_ -= 2;
    }
    if (parent_->pressedS){
        if ((y_ + pixmap().height()+4) < parent_->ySize_ )
            y_ += 2;
    }

    setPos(x_, y_);
}