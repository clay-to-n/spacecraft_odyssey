#include "gamewindow.h"

/** Default constructor.  Initializes various variables, creates a new scene and a new view, and creates pointers to every image used in the game.  Creates the scrolling background images, as well as items that will display the player's name and score.  Also sets up the timer.
*/
GameWindow::GameWindow()  {

	pressedW = false;
	pressedA = false;
 	pressedS = false;
	pressedD = false;
	pressedSpace = false;
	invincibleMode = false;

	scene = new QGraphicsScene();
	view = new QGraphicsView(scene);
	view->show();
		
	healthImage = new QPixmap ("sprites/health_bar.png");
	healthItemImage = new QPixmap ("sprites/health_item.png");
	scoreItemImage = new QPixmap ("sprites/points_item.png");	
	playerProjectileImage = new QPixmap ("sprites/player_projectile.png");
	enemyProjectileImage = new QPixmap ("sprites/enemy_projectile.png");
	bossProjectileImage = new QPixmap ("sprites/boss_projectile.png");
	backgroundImage = new QPixmap ("sprites/backgroundnoclouds.png");
	backgroundImage2 = new QPixmap ("sprites/backgroundnoclouds.png");
	cloudsImage = new QPixmap ("sprites/backgroundclouds.png");
	cloudsImage2 = new QPixmap ("sprites/backgroundclouds.png");
    playerImage = new QPixmap ("sprites/toss_arbiter.png");
    longRange1Image = new QPixmap ("sprites/toss_scout.gif");
    closeRange1Image = new QPixmap ("sprites/toss_corsair.gif");
    longRange2Image = new QPixmap ("sprites/terran_wraith.gif");
    closeRange2Image = new QPixmap ("sprites/terran_valkyrie.gif");
    boss1Image = new QPixmap ("sprites/toss_carrier.gif");
    boss2Image = new QPixmap ("sprites/terran_bc.gif");
    boss3Image = new QPixmap ("sprites/toss_arbiter.gif");
    explosionImage = new QPixmap ("sprites/explosion.png");
    explosion2Image = new QPixmap ("sprites/explosion2.png");

    bg_ = new ScrollingBackground(*backgroundImage, this, scene);
    bg2_ = new ScrollingBackground(*backgroundImage2, this, scene);
    clouds_ = new ScrollingBackground(*cloudsImage, this, scene);
    clouds2_ = new ScrollingBackground(*cloudsImage2, this, scene);

	view->setSceneRect(0.0, 0.0, 480, 580);	

    scene->addItem(bg_);
    scene->addItem(bg2_);
    scene->addItem(clouds_);
    scene->addItem(clouds2_);

    timerClouds = 4;
    bg2_->setIntPos(0, (-(4360+4460+505)));
    clouds2_->setIntPos(0, (-(4360+4460+505)));

    playerName = new QGraphicsSimpleTextItem();
    playerScore = new QGraphicsSimpleTextItem();
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

/** Associates the GameWindow object with a MainWindow
* @param MainWindow The MainWindow to associate the GameWindow with
*/
void GameWindow::setMainWindow(MainWindow *mainWindow)
{
	mainWindow_ = mainWindow;
}

/** Starts the game in Normal mode by creating a new Player, drawing the GUI (player name and score), and starting the timer
*/
void GameWindow::startGame()
{
	invincibleMode = false;
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
	QBrush * greenBrush = new QBrush(QColor(51,222,95,180));
	QFont * font = new QFont();
	font->setCapitalization(QFont::AllUppercase);
	font->setPointSize(11);
	playerName->setPos(43, 516);
	playerName->setBrush(*greenBrush);
	playerName->setFont(*font);
	playerName->setZValue(8);
	playerScore->setPos(320, 540);
	scoreCount = 0;
	playerScore->setText("Score: 0");
	playerScore->setBrush(*greenBrush);
	playerScore->setFont(*font);
	playerScore->setZValue(8);
	scene->addItem(playerName);
	scene->addItem(playerScore);
	scoreCount = 0;
	timerCount = 0;
	levelCount = 0;
	timerMax = 400;
	timer->start();

	error->setText("Move using WASD keys.  Shoot with Spacebar.");
}

/** Starts the game in Invincible mode by creating a new Player, drawing the GUI (player name and score), and starting the timer
*/
void GameWindow::startInvincibleGame()
{
	invincibleMode = true;
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
	QBrush * greenBrush = new QBrush(QColor(51,222,95,180));
	QFont * font = new QFont();
	font->setCapitalization(QFont::AllUppercase);
	font->setPointSize(11);
	playerName->setPos(43, 516);
	playerName->setBrush(*greenBrush);
	playerName->setFont(*font);
	playerName->setZValue(8);
	playerScore->setPos(320, 540);
	scoreCount = 0;
	playerScore->setText("Score: 0");
	playerScore->setBrush(*greenBrush);
	playerScore->setFont(*font);
	playerScore->setZValue(8);
	scene->addItem(playerName);
	scene->addItem(playerScore);
	scoreCount = 0;
	timerCount = 0;
	levelCount = 0;
	timerMax = 400;
	timer->start();
	error->setText("Move using WASD keys.  Shoot with Spacebar.  You're invincible!");

}

/** This slot is where all movement of objects occurs based on the clock.  It also handles all collisions.  It spawns enemies and items according to the timer.  It checks if things are dead, and removes them if they are.  It update's the player's health and score in the GUI.  It displays explosion animations when most objects collide.
*/
void GameWindow::handleTimer() 
{
	//To move the Background
	if (timerCount % (3*timerClouds) == 0)
	{
		bg_->move();
		bg2_->move();	
		if (bg_->y() == -4360 ) {
				bg2_->setIntPos(0, -(4360+4460+505));
		}
		if (bg2_->y() == -4360 ) {
				bg_->setIntPos(0, -(4360+4460+540));
		}
	}
	
	//To move the Clouds
	if (timerCount % timerClouds == 0)
	{
		clouds_->move();
		clouds2_->move();	
		if (clouds_->y() == -4360 ) {
			clouds2_->setIntPos(0, -(4360+4460+505));
		}
		if (clouds2_->y() == -4360 ) {
			clouds_->setIntPos(0, -(4360+4460+540));
		}
	}
	
	//For every thing
    for (int i = 0; i < things_.size(); i++)
    {
    	//To get points to move toward the player
    	if (dynamic_cast<ScoreItem*>(things_.at(i)) != NULL && things_.at(i)->cooldown > 50 && things_.at(i)->cooldown % 15-things_.at(i)->random == 3)
    	{
    		if (things_.at(i)->x() < things_.at(0)->x() && things_.at(i)->y() < things_.at(0)->y())
    		{
    			things_.at(i)->setIntVel(1, 3);
    			if (things_.at(i)->y() > things_.at(0)->y() - 150)
    				things_.at(i)->setIntVel(3, 3);
    		}
    		else if (things_.at(i)->x() < things_.at(0)->x() && things_.at(i)->y() > things_.at(0)->y())
    		{
    			things_.at(i)->setIntVel(1, -3);
    			if (things_.at(i)->y() > things_.at(0)->y() - 150)
    				things_.at(i)->setIntVel(3, -3);
    		}
    		else if (things_.at(i)->x() > things_.at(0)->x() && things_.at(i)->y() < things_.at(0)->y())
    		{
    			things_.at(i)->setIntVel(-1, 3);
    			if (things_.at(i)->y() > things_.at(0)->y() - 150)
    				things_.at(i)->setIntVel(-3, 3);
    		}
    		else if (things_.at(i)->x() > things_.at(0)->x() && things_.at(i)->y() > things_.at(0)->y())
    		{
    			things_.at(i)->setIntVel(-1, -3);
    			if (things_.at(i)->y() > things_.at(0)->y() - 150)
    				things_.at(i)->setIntVel(-3, -3);
    		}

    	}

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

	    //To trigger boss attack
	    if (things_.at(i)->shoots && things_.at(i)->health_ > 3)
    	{
    		//Normal Boss Attack
			if (timerCount % 800 == 200)
			{
				for (int w = 0; w < 7; w++) {
					EnemyProjectile * bossAttack = new EnemyProjectile(*bossProjectileImage, this, scene);
			        things_.push_back(bossAttack);
			        bossAttack->setIntPos(((things_.at(i)->x())+.45*(things_.at(i)->pixmap().width())), ((things_.at(i)->y())+10));
			        bossAttack->setVelocity((w-3), (4-abs(w-3)));
			        scene->addItem(bossAttack);
			    }
			}
			//Boss 2 special attack
			if (timerCount % 1600 == 300 && things_.at(i)->level == 1)
			{
				for (int w = 0; w < 5; w++) {
					EnemyProjectile * bossAttack = new EnemyProjectile(*bossProjectileImage, this, scene);
			        things_.push_back(bossAttack);
			        bossAttack->setIntPos(((things_.at(i)->x())+.45*(things_.at(i)->pixmap().width())), ((things_.at(i)->y())+10));
			        bossAttack->setVelocity((w-2), 2);
			        scene->addItem(bossAttack);
			    }
			}
			//Boss 3 special attack
			if (timerCount % 800 == 790 && things_.at(i)->level == 2)
			{
				for (int w = 0; w < 7; w++) {
					EnemyProjectile * bossAttack = new EnemyProjectile(*bossProjectileImage, this, scene);
			        things_.push_back(bossAttack);
			        bossAttack->setIntPos(((things_.at(i)->x())+.45*(things_.at(i)->pixmap().width())), ((things_.at(i)->y())+10));
			        bossAttack->setVelocity((w-3), (4-abs(w-3)));
			        scene->addItem(bossAttack);
			    }
			}
		}

		//To check for collisions
		for (int j = 0; j < things_.size(); j++)
		{
			if (things_.at(i)->collidesWithItem(things_.at(j)))
			{
				if (dynamic_cast<Player*>(things_.at(i)) != NULL || dynamic_cast<PlayerProjectile*>(things_.at(i)) != NULL) 
				{
					if (dynamic_cast<EnemyProjectile*>(things_.at(j)) != NULL || dynamic_cast<EnemyCloseRange*>(things_.at(j)) != NULL || dynamic_cast<EnemyLongRange*>(things_.at(j)) != NULL || dynamic_cast<EnemyBoss*>(things_.at(j)) != NULL ) {
						-- things_.at(j)->health_ ;
	    				-- things_.at(i)->health_ ;
	    				
	    				//If it hit the player, remove it and decrease health
	    				if (dynamic_cast<Player*>(things_.at(i)) != NULL)
	    				{
	    					things_.at(j)->health_ = 0;
	    					scene->removeItem(health_.back());
    						delete health_.back();
    						health_.remove(health_.size() - 1);
	    				}

	    				//If a boss is defeated, increase difficulty
	    				if (dynamic_cast<EnemyBoss*>(things_.at(j)) != NULL && things_.at(j)->health_ == 0)
	    				{
	    					if (timerClouds > 2)
	    						timerClouds --;
	    					timerCount = 0;
	    					levelCount ++;
							if (speed > 5) {
								speed = speed - 1;
								timerMax = timerMax*(speed+1/(speed));
								timer->setInterval(speed);
								timerCount = 0;
							}
							else if (speed > 3) {
								speed = speed - 0.5;
								timerMax = timerMax*(speed+0.5/(speed));
								timer->setInterval(speed);
								timerCount = 0;
							}

	    				}
					}
				
					//To check if the player picked up Health item
					if (dynamic_cast<Player*>(things_.at(i)) != NULL && dynamic_cast<HealthItem*>(things_.at(j)) != NULL)
					{
						if (health_.size() < 5) {
							things_.at(j)->health_ = 0;
							++ things_.at(i)->health_ ;
							health = new Health(*healthImage, this, scene);
							health->setNum(health_.size());
							health_.push_back(health);
							scene->addItem(health);
						}
					}

					//To check if the player picked up Score item
					if (dynamic_cast<Player*>(things_.at(i)) != NULL && dynamic_cast<ScoreItem*>(things_.at(j)) != NULL)
					{
							things_.at(j)->health_ = 0;
							scoreCount += things_.at(j)->score;
							
					}
					

				}
			}
		}

    	//To move the things
    	things_.at(i)->move();


    	//To regain health in Invincible Mode
		if (invincibleMode && player->health_ < 1)
		{
			player->health_ = 5;
			for (int i = 0; i < 5; i++)
			{
				health = new Health(*healthImage, this, scene);
				health->setNum(i);
				health_.push_back(health);
				scene->addItem(health);
			}
		}

    	//To remove dead or off-screen things
    	if (things_.at(i)->offscreen == true)
    	{
    		scene->removeItem(things_.at(i));
    		delete things_.at(i);
    		things_.remove(i);
    	}
    	if (things_.at(i)->health_ < 1)
    	{
    		//If they're dead, let's show an image
    		if (dynamic_cast<HealthItem*>(things_.at(i)) == NULL && dynamic_cast<Explosion*>(things_.at(i)) == NULL && dynamic_cast<ScoreItem*>(things_.at(i)) == NULL)
    		{
	    		Explosion * explode = new Explosion(*explosionImage, this, scene);
	    		things_.push_back(explode);
	    		explode->setIntPos(things_.at(i)->x(), things_.at(i)->y());
	    		scene->addItem(explode);

	    		//Let's also create Points
	    		for (int k = 0; k < (things_.at(i)->score)/5; k++)
	    		{
	    			ScoreItem * scoreItem = new ScoreItem(*scoreItemImage, this, scene);
	    			things_.push_back(scoreItem);
	    			scoreItem->setIntPos(things_.at(i)->x(), things_.at(i)->y());
	    			scoreItem->random = i;
	    			scene->addItem(scoreItem);

	    		}
	    	}
	    	if (dynamic_cast<Explosion*>(things_.at(i)) != NULL)
    		{
    			Explosion * expCheck= dynamic_cast<Explosion*>(things_.at(i));
    			if (expCheck->linger == false)
    			{
		    		Explosion * explode2 = new Explosion(*explosion2Image, this, scene);
		    		explode2->makeLinger();
		    		things_.push_back(explode2);
		    		explode2->setIntPos(things_.at(i)->x(), things_.at(i)->y());
		    		scene->addItem(explode2);
		    	}	
	    	}
    		scene->removeItem(things_.at(i));
    		delete things_.at(i);
    		things_.remove(i);
    	}
    }

	//To spawn new things
	if (timerCount > 600 && timerCount % 200 == 2) {
		if (levelCount % 3 == 1) {
			EnemyCloseRange *enemyC = new EnemyCloseRange(*closeRange2Image, this, scene);
			things_.push_back(enemyC);
			scene->addItem(enemyC);
		}
		else {
			EnemyCloseRange *enemyC = new EnemyCloseRange(*closeRange1Image, this, scene);
			things_.push_back(enemyC);
			scene->addItem(enemyC);
		}	
		
	}	

	if (timerCount > 3500 && timerCount < 4200 && timerCount % 150 == 100) {
		if (levelCount % 3 == 1) {
			EnemyCloseRange *enemyC = new EnemyCloseRange(*closeRange2Image, this, scene);
			things_.push_back(enemyC);
			scene->addItem(enemyC);
		}
		else {
			EnemyCloseRange *enemyC = new EnemyCloseRange(*closeRange1Image, this, scene);
			things_.push_back(enemyC);
			scene->addItem(enemyC);
		}
	}
	if (timerCount > 1300 && timerCount % 600 == 100) {
		if (levelCount % 3 == 1) {
			EnemyLongRange *enemyL = new EnemyLongRange(*longRange2Image, this, scene);
			things_.push_back(enemyL);
			scene->addItem(enemyL);
		}
		else {
			EnemyLongRange *enemyL = new EnemyLongRange(*longRange1Image, this, scene);
			things_.push_back(enemyL);
			scene->addItem(enemyL);
		}
	}	
	if (timerCount > 2500 && timerCount < 2750 && timerCount % 80 == 50) {
		if (levelCount % 3 != 0) {
			EnemyLongRange *enemyL = new EnemyLongRange(*longRange2Image, this, scene);
			things_.push_back(enemyL);
			scene->addItem(enemyL);
		}
		else {
			EnemyLongRange *enemyL = new EnemyLongRange(*longRange1Image, this, scene);
			things_.push_back(enemyL);
			scene->addItem(enemyL);
		}
	}	

	if (timerCount == 4000) {
		//To choose which boss to spawn
		EnemyBoss *enemyB = NULL;
		switch(levelCount % 3)
		{
			case 0:
				enemyB = new EnemyBoss(*boss1Image, this, scene);
				enemyB->setLevel(0);
				break;
			case 1:
				enemyB = new EnemyBoss(*boss2Image, this, scene);
				enemyB->setLevel(1);
				break;
			case 2:
				enemyB = new EnemyBoss(*boss3Image, this, scene);
				enemyB->setLevel(2);
				break;
		}
			things_.push_back(enemyB);
			scene->addItem(enemyB);
	}

	//To spawn health
	if (timerCount % 3000 == 1200) {
		HealthItem *healthI = new HealthItem(*healthItemImage, this, scene);
		things_.push_back(healthI);
		scene->addItem(healthI);
	}		

	//To shoot player projectiles
	if (pressedSpace && things_.at(0)->cooldown > 30)
	{
		things_.at(0)->cooldown = 0;
        PlayerProjectile * playerBullet = new PlayerProjectile(*playerProjectileImage, this, scene);
        things_.push_back(playerBullet);
        playerBullet->setIntPos(((things_.at(0)->x())+.45*(things_.at(0)->pixmap().width())), ((things_.at(0)->y())+10));
        scene->addItem(playerBullet);
    }

    //To check if player died
    if (player->health_ < 1) {
    	timer->stop();
    	error->setText("You've Died!  Quit and Restart to play again.");

    	//Add his score to the high score list, and display the high score list
    	QBrush * greenBrush = new QBrush(QColor(51,222,95,250));
		QFont * font = new QFont();
		font->setCapitalization(QFont::AllUppercase);
		font->setPointSize(13);
		QGraphicsSimpleTextItem* highScore = new QGraphicsSimpleTextItem;
    	highScore->setPos(43, 60);
		highScore->setBrush(*greenBrush);
		highScore->setFont(*font);
		highScore->setZValue(8);
		QString tempText = "High Scores:" ;
		highScore->setText(tempText);
		scene->addItem(highScore);

    	if ((ScoreList->size() < 9 || scoreCount > ScoreList->at(ScoreList->size()-1).getScore()))
    	{
    		ScoreEntry tempEntry(playerNameString, scoreCount);
    		ScoreList->push_back(tempEntry);
    		std::sort(ScoreList->begin(), ScoreList->end());
    		std::reverse(ScoreList->begin(), ScoreList->end());
    		if (ScoreList->size() > 10)
    			ScoreList->pop_back();

    	}

		ofstream fout;
		fout.open("scores.txt");

		for (unsigned int i = 0; i < ScoreList->size(); i++)
	    {
	    	QGraphicsSimpleTextItem* scoreDisplay = new QGraphicsSimpleTextItem;
	    	scoreDisplay->setPos(43, 120+(i*30));
			scoreDisplay->setBrush(*greenBrush);
			scoreDisplay->setFont(*font);
			scoreDisplay->setZValue(8);
			tempText = "        ";
			tempText += QString::number(ScoreList->at(i).getScore());
			tempText += ": ";
			tempText += ScoreList->at(i).getName();
			scoreDisplay->setText(tempText);
			scene->addItem(scoreDisplay);

	        fout << ScoreList->at(i).getScore() << ' ';
	        fout << ScoreList->at(i).getName().toStdString() << '\n';
	    }

	    fout.close();
    }

    //To update player's score
    scoreString = "Score: ";
    scoreString += QString::number(scoreCount);
    playerScore->setText(scoreString);

    timerCount++;

}