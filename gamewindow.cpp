#include "gamewindow.h"

/** Default constructor.  Creates a board, then calls setBoard on it to add it to the gameplay window.  Also initializes and connects the timer.
*/
GameWindow::GameWindow()  {

	//Create new board, then iterate through and create a GUITile for each board tile in the correct location

	pressedW = false;
	pressedA = false;
 	pressedS = false;
	pressedD = false;

	scene = new QGraphicsScene();
	view = new QGraphicsView(scene);
	view->show();
		
	backgroundImage = new QPixmap ("sprites/starcraftbackground.jpg");
	backgroundImage2 = new QPixmap ("sprites/starcraftbackground.jpg");
    playerImage = new QPixmap ("sprites/toss_arbiter.png");
    longRange1Image = new QPixmap ("sprites/toss_scout.gif");
    closeRange1Image = new QPixmap ("sprites/toss_corsair.gif");
    boss1Image = new QPixmap ("sprites/toss_carrier.gif");


    bg_ = new ScrollingBackground(*backgroundImage, this, scene);
    bg2_ = new ScrollingBackground(*backgroundImage2, this, scene);

	view->setSceneRect(0.0, 0.0, 480, 580);	


    scene->addItem(bg_);
    scene->addItem(bg2_);

    bg2_->setIntPos(0, (-(4360+4460+505)));


    timer = new QTimer();
    speed = 8; 
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
	timerCount = 0;
	timerMax = 200;
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
	if (timerCount % 6 == 0)
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
	
	//To move the things
    for (int i = 0; i < things_.size(); i++)
    {
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
	if (timerCount % 100 == 2)
	{
		EnemyCloseRange *enemyC = new EnemyCloseRange(*closeRange1Image, this, scene);
		things_.push_back(enemyC);
		scene->addItem(enemyC);

	}	
	//Have these things happen when a boss is defeated
	if (timerCount == timerMax)
	{
		timerCount = 0;
		if (speed > 2) {
			speed --;
			timerMax = timerMax*(speed+1/(speed));
			timer->setInterval(speed);
		}
	}
}