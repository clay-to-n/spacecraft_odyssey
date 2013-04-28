#include "player.h"
#include "gamewindow.h"

/** Default constructor.  Creates a Player with the specified parameters.
* @param width The width of the tile
* @param height The height of the tile
* @param x The x-position of the tile
* @param y The y-position of the tile
* @param num The number displayed on the tile
* @param parent The GameWindow object which created this Player
*/
//Player::Player(int width, int height, int x, int y, GameWindow *parent) :
    //QGraphicsPixmapItem(x, y, width, height) {

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

/** Implementation of mousePressEvent to move the tile.
* @param e Standard mouse click pointer implementation
*/
void Player::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    //parent_->moveTile(this);
}

/** Moves the Player by updating it's position and calling rectangle's moveTo function.
* @param x The x distance to move
* @param y The y distance to move
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