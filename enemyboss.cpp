#include "enemyboss.h"
#include "gamewindow.h"

/** Default constructor.  Creates a EnemyBoss with the specified parameters.
* @param width The width of the tile
* @param height The height of the tile
* @param x The x-position of the tile
* @param y The y-position of the tile
* @param num The number displayed on the tile
* @param parent The GameWindow object which created this EnemyBoss
*/
//EnemyBoss::EnemyBoss(int width, int height, int x, int y, GameWindow *parent) :
    //QGraphicsPixmapItem(x, y, width, height) {

EnemyBoss::EnemyBoss(QPixmap & pixmap, GameWindow * parent, QGraphicsScene *scene) : Thing(pixmap, 0, 0)
{ 

    shoots = true;
    offscreen = false;
    srand(time(NULL));
    barrierTemp = rand()%60;
    scene_ = scene;
    parent_ = parent;
    cooldown = (200 );
    vy_ = 1;
    x_ = (240);
    vx_ = (-1 + (rand() % 3));
    y_ = -50;
    setPos(x_, y_);
    setZValue(5);
    yBarrier = (100);
    health_ = 5;
}

/** Destructor */
EnemyBoss::~EnemyBoss()
{

}

/** Implementation of mousePressEvent to move the tile.
* @param e Standard mouse click pointer implementation
*/
void EnemyBoss::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    //parent_->moveTile(this);
}

/** Moves the EnemyBoss by updating it's position and calling rectangle's moveTo function.
* @param x The x distance to move
* @param y The y distance to move
*/
void EnemyBoss::move()
{
    cooldown++;

    if (y_ > parent_->ySize_ )
        offscreen = true;
    if (y_ > yBarrier-barrierTemp && vy_ > 0)
    {
        vy_ = -vy_;
        if (vx_ == 0)
            vx_ = -1;
        barrierTemp = rand()%60;
    }
    if ( vy_ < 0 && y_ < -40)
    {
        vy_ = -vy_;
    }
    if (x_ < 0 || x_ > (parent_->xSize_ - pixmap().width()))
        vx_ = -vx_;
    //else
    y_ += vy_;
    x_ += vx_;
    setPos(x_, y_);
}