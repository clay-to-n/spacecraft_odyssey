#include "enemyboss.h"
#include "gamewindow.h"

/** Default constructor.  Creates a Boss with the specified parameters.
* @param pixmap The Pixmap to display this object with
* @param parent The GameWindow which created this object
* @param scene The scene in which this object exists
*/
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
    health_ = 7;
    vxDefault = -1;
    vyDefault = -1;
    level = 0;
}

/** Destructor */
EnemyBoss::~EnemyBoss()
{

}

/** Changes certain aspects of the Boss's behaviour based on which boss it is.
* @param levelCount 0 designates the first boss, 1 the second, and 2 the third.
*/
void EnemyBoss::setLevel(int levelCount)
{
    health_ += levelCount;
    switch (levelCount % 3){
        case 0:
            level = 0;
            score = 100;
            break;
        case 1:
            level = 1;
            health_ += 2*levelCount;
            vxDefault = 1;
            vyDefault = 0;
            score = 150;
            break;
        case 2:
            level = 2;
            vxDefault = -2;
            yBarrier = 250;
            score = 300;
            break;
    }

}

/** Moves the EnemyBoss by updating it's position according to it's level and velocities.
*/
void EnemyBoss::move()
{
    cooldown++;
    if (level > 0 && cooldown < 150)
    {
        cooldown++;
    }

    if (y_ > parent_->ySize_ )
        offscreen = true;
    if (y_ > yBarrier-barrierTemp && vy_ > 0)
    {
        vy_ = vyDefault;
        if (vx_ == 0)
            vx_ = vxDefault;
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