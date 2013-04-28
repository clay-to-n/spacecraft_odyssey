#include "gamewindow.h"

/** Default constructor.  Creates a board, then calls setBoard on it to add it to the gameplay window.  Also initializes and connects the timer.
*/
GameWindow::GameWindow()  {

	//Create new board, then iterate through and create a GUITile for each board tile in the correct location

	pressedW = false;
	pressedA = false;
 	pressedS = false;
	pressedD = false;
	pressedSpace = false;

	scene = new QGraphicsScene();
	view = new QGraphicsView(scene);
	view->show();
		
	healthImage = new QPixmap ("sprites/health_bar.png");	
	playerProjectileImage = new QPixmap ("sprites/player_projectile.png");
	enemyProjectileImage = new QPixmap ("sprites/enemy_projectile.png");
	backgroundImage = new QPixmap ("sprites/backgroundnoclouds.png");
	backgroundImage2 = new QPixmap ("sprites/backgroundnoclouds.png");
	cloudsImage = new QPixmap ("sprites/backgroundclouds.png");
	cloudsImage2 = new QPixmap ("sprites/backgroundclouds.png");
    playerImage = new QPixmap ("sprites/toss_arbiter.png");
    longRange1Image = new QPixmap ("sprites/toss_scout.gif");
    closeRange1Image = new QPixmap ("sprites/toss_corsair.gif");
    boss1Image = new QPixmap ("sprites/toss_carrier.gif");


    bg_ = new ScrollingBackground(*backgroundImage, this, scene);
    bg2_ = new ScrollingBackground(*backgroundImage2, this, scene);
    clouds_ = new ScrollingBackground(*cloudsImage, this, scene);
    clouds2_ = new ScrollingBackground(*cloudsImage2, this, scene);

	view->setSceneRect(0.0, 0.0, 480, 580);	


    scene->addItem(bg_);
    scene->addItem(bg2_);
    scene->addItem(clouds_);
    scene->addItem(clouds2_);


    bg2_->setIntPos(0, (-(4360+4460+505)));
    clouds2_->setIntPos(0, (-(4360+4460+505)));


    timer = new QTimer();
    speed = 9; //9
    timer->setInterval(speed);
    connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
	



}

/** Destructor */
GameWindow::~GameWindow() 
{
	if (timer->isActive())
		timer->stop();
	delete view;
	delete scene;
	delete timer;
}

void GameWindow::setMainWindow(MainWindow *mainWindow)
{
	mainWindow_ = mainWindow;
}

void GameWindow::startGame()
{
	things_.clear();
	player = new Player(*playerImage, this, scene);
	things_.push_back(player);
	scene->addItem(player);
	for (int i = 0; i < 5; i++)
	{
		health = new Health(*healthImage, this, scene);
		health->setNum(i);
		health_.push_back(health);
		scene->addItem(health);
	}
	timerCount = 0;
	timerMax = 400;
	timer->start();
	error->setText("Move using WASD keys.  Shoot with Spacebar.");


}


/*void GameWindow::setBoard(Board *b)
{

	int dim = static_cast<int>(sqrt(b_->getSize()));
	int width = 449/dim;
	tileSize = width;
	int * tilesTemp = b_->getTiles();
	int var = (255/(b_->getSize()));
	for (int i = 0; i < b_->getSize(); i++)
	{	
		QBrush * tempBrush = new QBrush(QColor(100+(tilesTemp[i]*.25*var),(tilesTemp[i]*var),(255-(tilesTemp[i]*var)/2),(50+10*tilesTemp[i])));
		GUITile * temp = new GUITile(width, width, (width*(i%dim)), (width*(i/dim)), tilesTemp[i], this);
		temp->setBrush(*tempBrush);
		brushes_.push_back(tempBrush);
		tiles_.push_back(temp);
		if (tilesTemp[i] != 0)
		{
			scene->addItem(tiles_[i]);
		}
	}
}*/


/** Moves the tile specified by determining which direction it must move in and then starting the timer.
* @param tile Pointer to the tile to move
*/
void GameWindow::moveObject()
{
/*
	if (timer_->isActive()) return;
	timerTile = tile;
	int * tilesTemp = b_->getTiles();
	int empty = -1;
	int position = -1;
	timerX = 0;
	timerY = 0;
	int dim = static_cast<int>(sqrt(b_->getSize()));
	timerCount = 0;
	timerMax = tileSize;

	for (int i = 0; i < b_->getSize(); i++)
    {
      if (tilesTemp[i] == 0)
        empty = i;
    }
    for (int j = 0; j < (b_->getSize()); j++)
    {
      if (tilesTemp[j] == tile->getNum())
        position = j;
    }

	if (position == empty + 1)
	{
		//The blank is to the left of the tile
		timerX = -1;
		timerY = 0;
		timer_->start();
	}
	else if (position == empty - 1)
	{
		//The blank is to the right of the tile
		timerX = 1;
		timerY = 0;
		timer_->start();
	
	}
	else if (position == empty + dim)
	{
		//The blank is up from the tile
		timerX = 0;
		timerY = -1;
		timer_->start();
		
	}
	else if (position == empty - dim)
	{
		//The blank is down from the tile
		timerX = 0;
		timerY = 1;
		timer_->start();
	
	}
	b_->move(tile->getNum());
	timerCount = 0;
	if (b_->solved())
		error->setText("Board is solved!");*/
}



/** This slot moves the tile by one pixel per tick of the timer by calling the GUITile's move function.
*/
void GameWindow::handleTimer() 
{
	//To move the Background
	if (timerCount % 12 == 0)
	{
		bg_->move();
		bg2_->move();	

		if (bg_->y() == -4360 )
		{
				bg2_->setIntPos(0, -(4360+4460+505));
		}

		if (bg2_->y() == -4360 )
		{
				bg_->setIntPos(0, -(4360+4460+540));
		}
	}

	if (timerCount % 4 == 0)
	{
	
		clouds_->move();
		clouds2_->move();	

		if (clouds_->y() == -4360 )
		{
				clouds2_->setIntPos(0, -(4360+4460+505));
		}

		if (clouds2_->y() == -4360 )
		{
				clouds_->setIntPos(0, -(4360+4460+540));
		}
	}
	
	//For every thing
    for (int i = 0; i < things_.size(); i++)
    {
    	//To get enemies to shoot
    	if (things_.at(i)->shoots)
    	{
    		if (things_.at(i)->cooldown == 400)
    			things_.at(i)->cooldown = 0;
    		if (things_.at(i)->cooldown == 200)
    		{
	    	EnemyProjectile * enemyBullet = new EnemyProjectile(*enemyProjectileImage, this, scene);
	        things_.push_back(enemyBullet);
	        enemyBullet->setIntPos(((things_.at(i)->x())+.45*(things_.at(i)->pixmap().width())), ((things_.at(i)->y())+10));
	        scene->addItem(enemyBullet);
	        things_.at(i)->cooldown = 0;
	    	}
	    	things_.at(i)->cooldown++;
    	}

    	//To move the things
    	things_.at(i)->move();
    	if (things_.at(i)->offscreen == true)
    	{
    		scene->removeItem(things_.at(i));
    		delete things_.at(i);
    		things_.remove(i);
    	}
    }

	timerCount++;

	//To spawn new things
	if (timerCount % 200 == 2)
	{
		EnemyCloseRange *enemyC = new EnemyCloseRange(*closeRange1Image, this, scene);
		things_.push_back(enemyC);
		scene->addItem(enemyC);

	}	

	if (timerCount % 600 == 100)
	{
		EnemyLongRange *enemyL = new EnemyLongRange(*longRange1Image, this, scene);
		things_.push_back(enemyL);
		scene->addItem(enemyL);

	}	

	//To shoot player projectiles
	if (pressedSpace && timerCount % 20 == 0)
	{
        PlayerProjectile * playerBullet = new PlayerProjectile(*playerProjectileImage, this, scene);
        things_.push_back(playerBullet);
        playerBullet->setIntPos(((things_.at(0)->x())+.45*(things_.at(0)->pixmap().width())), ((things_.at(0)->y())+10));
        scene->addItem(playerBullet);
    }


	//Have these things happen when a boss is defeated
	if (timerCount == timerMax)
	{
		timerCount = 0;
		if (speed > 2) {
			speed = speed - 0.5;
			timerMax = timerMax*(speed+0.5/(speed));
			timer->setInterval(speed);
		}
	}
}