#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QtGui/QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QListView>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QBrush>
#include <QApplication>
#include <QPixmap>
#include <ostream>
#include <QVector>
#include <QBrush>
#include <QFont>
#include <QString>
#include <cmath>
#include <iostream>
#include "mainwindow.h"
#include "player.h"
#include "health.h"
#include "healthitem.h"
#include "enemycloserange.h"
#include "enemylongrange.h"
#include "enemyboss.h"
#include "scrollingbackground.h"
#include "playerprojectile.h"
#include "enemyprojectile.h"
#include "explosion.h"

/**
  This class will be the window in which the game is run.  It will be filled with GUITiles which the user will ineract with.
  */
class MainWindow;

class GameWindow : public QGraphicsView
{
	Q_OBJECT

public:
	explicit GameWindow();
    ~GameWindow();
    QGraphicsView *view;
	QGraphicsScene *scene;
	bool pressedW;
	bool pressedA;
	bool pressedS;
	bool pressedD;
	bool pressedSpace;
	bool invincibleMode;
	QGraphicsSimpleTextItem* playerName;
	QGraphicsSimpleTextItem* playerScore;
	//void setBoard(Board *b);
	void setMainWindow(MainWindow *mainWindow);
	void startGame();
	void startInvincibleGame();
	/** Vector of GUITiles which will be displayed. */
	QLineEdit *error;
	/** Pointer to the board class that is being used. */
	static const int xSize_ = 482;
	static const int ySize_ = 582;
	QTimer* timer;


private:
	int timerCount;
	int levelCount;
	int timerMax;
	//int tileSize;
	int speed;
	int timerX;
	int timerY;
	int scoreCount;
	int timerClouds;

	QVector<Thing*> things_;
	QVector<Thing*> health_;
	ScrollingBackground * bg_;	
	ScrollingBackground * bg2_;
	ScrollingBackground * clouds_;	
	ScrollingBackground * clouds2_;
	MainWindow * mainWindow_;
	QPixmap * healthImage;
	QPixmap * healthItemImage;
	QPixmap * playerProjectileImage;	
	QPixmap * enemyProjectileImage;
	QPixmap * bossProjectileImage;
	QPixmap * backgroundImage;
	QPixmap * backgroundImage2;
	QPixmap * cloudsImage;
	QPixmap * cloudsImage2;
	QPixmap * playerImage;
	QPixmap * longRange1Image;
	QPixmap * closeRange1Image;
	QPixmap * boss1Image;
	QPixmap * boss2Image;
	QPixmap * boss3Image;
	QPixmap * explosionImage;
	QPixmap * explosion2Image;
	QString scoreString;
	Player * player;
	Health * health;
	/** Pointer to a GUITile that will be animated. */
	
	/** Vector of QBrushes to use to color the tiles. */
	/** Pointer to a QTimer to be used for animation. */
	
public slots:
	void handleTimer();

};

#endif // GAMEWINDOW_H