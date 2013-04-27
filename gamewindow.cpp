#include "gamewindow.h"

/** Default constructor.  Creates a board, then calls setBoard on it to add it to the gameplay window.  Also initializes and connects the timer.
*/
GameWindow::GameWindow()  {

	//Create new board, then iterate through and create a GUITile for each board tile in the correct location


	scene = new QGraphicsScene();
	view = new QGraphicsView(scene);
	view->show();
		
	backgroundImage = new QPixmap ("sprites/starcraftbackground.jpg");
    playerImage = new QPixmap ("sprites/toss_arbiter.png");
    longRange1Image = new QPixmap ("sprites/toss_scout.gif");
    closeRange1Image = new QPixmap ("sprites/toss_corsair.gif");
    boss1Image = new QPixmap ("sprites/toss_carrier.gif");

    QGraphicsPixmapItem* background = new QGraphicsPixmapItem(*backgroundImage);

    scene->addItem(background);

    timer_ = new QTimer();
    timer_->setInterval(4);
    connect(timer_, SIGNAL(timeout()), this, SLOT(handleTimer()));
	



}

/** Destructor */
GameWindow::~GameWindow() 
{
	if (timer_->isActive())
		timer_->stop();
	delete view;
	delete scene;
	delete timer_;
}

void GameWindow::setMainWindow(MainWindow *mainWindow)
{
	mainWindow_ = mainWindow;
}

void GameWindow::startGame()
{
	player = new Player(*playerImage, this, scene);
	scene->addItem(player);
	timer_->start();
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
	    player->move();
    	timerCount++;
    	/*if (timerCount == timerMax)
    	{
    		timerCount = 0;
    		timer_->stop();
    		//timerTile = NULL;
    		timerX = 0;
    		timerY = 0;
    	}*/
}