#include "enemyprojectile.h"
#include "gamewindow.h"

/** Default constructor.  Creates an EnemyProjectile with the specified parameters.
* @param pixmap The Pixmap to display this object with
* @param parent The GameWindow which created this object
* @param scene The scene in which this object exists
*/
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

/** Sets the position of the Enemy Projectile (so that it starts where the object creating it is) as well as updating the x_ and y_ data members to reflect this.
* @param x The x position to use
* @param y The y position to use
*/
void EnemyProjectile::setIntPos(int x, int y)
{
    x_ = x;
    y_ = y;
    setPos(x_, y_);
}

/** Sets the velocity of the Enemy Projectile (so that different projectiles can have different speeds) as well as updating the vx_ and vy_ data members to reflect this.
* @param x The x position to use
* @param y The y position to use
*/
void EnemyProjectile::setVelocity(int vx, int vy)
{
    vx_ = vx;
    vy_ = vy;
}

/** Moves the EnemyProjectile by updating it's position based on its velocities and calling rectangle's moveTo function. */
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