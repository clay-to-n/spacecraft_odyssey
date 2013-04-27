#include "enemycloserange.h"
#include "gamewindow.h"

/** Default constructor.  Creates a EnemyCloseRange with the specified parameters.
* @param width The width of the tile
* @param height The height of the tile
* @param x The x-position of the tile
* @param y The y-position of the tile
* @param num The number displayed on the tile
* @param parent The GameWindow object which created this EnemyCloseRange
*/
//EnemyCloseRange::EnemyCloseRange(int width, int height, int x, int y, GameWindow *parent) :
    //QGraphicsPixmapItem(x, y, width, height) {

EnemyCloseRange::EnemyCloseRange(QPixmap & pixmap, GameWindow * parent, QGraphicsScene *scene) : Thing(pixmap, 0, 0)
{ 
    offscreen = false;
    srand(time(NULL));
    scene_ = scene;
    parent_ = parent;
    vy_ = 2;
    x_ = (rand() % 420 + 2);
    y_ = -50;
    setPos(x_, y_);
}

/** Destructor */
EnemyCloseRange::~EnemyCloseRange()
{

}

/** Implementation of mousePressEvent to move the tile.
* @param e Standard mouse click pointer implementation
*/
void EnemyCloseRange::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    //parent_->moveTile(this);
}

/** Moves the EnemyCloseRange by updating it's position and calling rectangle's moveTo function.
* @param x The x distance to move
* @param y The y distance to move
*/
void EnemyCloseRange::move()
{
    y_ += vy_;
    if (y_ > parent_->ySize_ )
        offscreen = true;
    setPos(x_, y_);
}