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

    scene_ = scene;
    parent_ = parent;
    x_ = 200;
    y_ = 500;
    setPos(x_, y_);
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
    
    if ((x_+pixmap().width()+2) < parent_->xSize_ && parent_->hasFocus())
        x_ += 1;
    //if ((y_+pixmap().height()+2) < parent_->ySize_)
      //  y_ += 1;
    //if (x_ > 2)
      //  x_ -= 1;
    //if (y_ > 2)
      //  y_ -= 1;

    setPos(x_, y_);
    // x_ += x;
    // y_ += y;


}