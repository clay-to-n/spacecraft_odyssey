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
	invincibleMode = false;

	scene = new QGraphicsScene();
	view = new QGraphicsView(scene);
	view->show();
		
	healthImage = new QPixmap ("sprites/health_bar.png");
	healthItemImage = new QPixmap ("sprites/health_item.png");	
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
    boss1Image = new QPixmap ("sprites/toss_carrier.gif");
    boss2Image = new QPixmap ("sprites/terran_bc.gif");
    boss3Image = new QPixmap ("sprites/toss_arbiter.gif");



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
	timerCount = 0;
	levelCount = 0;
	timerMax = 400;
	timer->start();

	error->setText("Move using WASD keys.  Shoot with Spacebar.");
}

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
	timerCount = 0;
	levelCount = 0;
	timerMax = 400;
	timer->start();
		error->setText("Move using WASD keys.  Shoot with Spacebar.  You're invincible!");

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
		if (bg_->y() == -4360 ) {
				bg2_->setIntPos(0, -(4360+4460+505));
		}
		if (bg2_->y() == -4360 ) {
				bg_->setIntPos(0, -(4360+4460+540));
		}
	}
	
	//To move the Clouds
	if (timerCount % 4 == 0)
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
					if (dynamic_cast<EnemyProjectile*>(things_.at(j)) != NULL || dynamic_cast<EnemyCloseRange*>(things_.at(j)) != NULL || dynamic_cast<EnemyLongRange*>(things_.at(j)) != NULL || dynamic_cast<EnemyBoss*>(things_.at(j)) != NULL) {
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
    	if (things_.at(i)->offscreen == true || things_.at(i)->health_ < 1)
    	{
    		scene->removeItem(things_.at(i));
    		delete things_.at(i);
    		things_.remove(i);
    	}
    }

	//To spawn new things
	if (timerCount > 600 && timerCount % 200 == 2) {
		EnemyCloseRange *enemyC = new EnemyCloseRange(*closeRange1Image, this, scene);
		things_.push_back(enemyC);
		scene->addItem(enemyC);
	}	

	if (timerCount > 3500 && timerCount < 4200 && timerCount % 150 == 100) {
		EnemyCloseRange *enemyC = new EnemyCloseRange(*closeRange1Image, this, scene);
		things_.push_back(enemyC);
		scene->addItem(enemyC);
	}
	if (timerCount > 1300 && timerCount % 600 == 100) {
		EnemyLongRange *enemyL = new EnemyLongRange(*longRange1Image, this, scene);
		things_.push_back(enemyL);
		scene->addItem(enemyL);
	}	
	if (timerCount > 2500 && timerCount < 2750 && timerCount % 80 == 50) {
		EnemyLongRange *enemyL = new EnemyLongRange(*longRange1Image, this, scene);
		things_.push_back(enemyL);
		scene->addItem(enemyL);
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
	if (pressedSpace && timerCount % 30 == 0)
	{
        PlayerProjectile * playerBullet = new PlayerProjectile(*playerProjectileImage, this, scene);
        things_.push_back(playerBullet);
        playerBullet->setIntPos(((things_.at(0)->x())+.45*(things_.at(0)->pixmap().width())), ((things_.at(0)->y())+10));
        scene->addItem(playerBullet);
    }

    timerCount++;

}