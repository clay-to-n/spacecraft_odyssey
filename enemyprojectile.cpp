#include "enemyprojectile.h"
#include "gamewindow.h"

/** Default constructor.  Creates a EnemyProjectile with the specified parameters.
* @param width The width of the tile
* @param height The height of the tile
* @param x The x-position of the tile
* @param y The y-position of the tile
* @param num The number displayed on the tile
* @param parent The GameWindow object which created this EnemyProjectile
*/
//EnemyProjectile::EnemyProjectile(int width, int height, int x, int y, GameWindow *parent) :
    //QGraphicsPixmapItem(x, y, width, height) {

EnemyProjectile::EnemyProjectile(QPixmap & pixmap, GameWindow * parent, QGraphicsScene *scene) : Thing(pixmap, 0, 0)
{ 
    shoots = false;
    offscreen = false;
    scene_ = scene;
    parent_ = parent;
    vy_ = 4;
    vx_ = 0;
    health_ = 3;
    setZValue(4);
    setPos(0,0);
}

/** Destructor */
EnemyProjectile::~EnemyProjectile()
{

}

/** Implementation of mousePressEvent to move the tile.
* @param e Standard mouse click pointer implementation
*/
void EnemyProjectile::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    //parent_->moveTile(this);
}

void EnemyProjectile::setIntPos(int x, int y)
{
    x_ = x;
    y_ = y;
    setPos(x_, y_);

}

void EnemyProjectile::setVelocity(int vx, int vy)
{
    vx_ = vx;
    vy_ = vy;
}

/** Moves the EnemyProjectile by updating it's position and calling rectangle's moveTo function.
* @param x The x distance to move
* @param y The y distance to move
*/
void EnemyProjectile::move()
{
    y_ += vy_;
    x_ += vx_;

    if (y_ > parent_->ySize_ )
        offscreen = true;
    if (x_ > parent_->xSize_ )
        offscreen = true;
    if (x_ < -10 )
        offscreen = true;

    setPos(x_, y_);
}