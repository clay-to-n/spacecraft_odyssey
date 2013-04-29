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

/** This class will be the window in which the game is run.  It will be filled with the player, enemies, items, and scrolling backgrounds.
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
	static const int xSize_ = 482;
	static const int ySize_ = 582;
	QGraphicsSimpleTextItem* playerName;
	QGraphicsSimpleTextItem* playerScore;
	void setMainWindow(MainWindow *mainWindow);
	void startGame();
	void startInvincibleGame();
	/** LineEdit which will display messages to the user */
	QLineEdit *error;
	/** Timer which controls all movements and events in the game */
	QTimer* timer;


private:
	int timerCount;
	int levelCount;
	int timerMax;
	int speed;
	int timerX;
	int timerY;
	int scoreCount;
	int timerClouds;

	/** QVector of everything to be displayed on the screen, besides the moving backgrounds */
	QVector<Thing*> things_;
	/** QVector of displayable health objects, to let the user know how much health they currently have*/
	QVector<Thing*> health_;
	/** Background image */
	ScrollingBackground * bg_;	
	/** Copy of background image to enable seamless scrolling*/
	ScrollingBackground * bg2_;
	/** Clouds image */
	ScrollingBackground * clouds_;
	/** Copy of clouds image to enable seamless scrolling */	
	ScrollingBackground * clouds2_;
	/** Pointer to the mainwindow which created this */
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
	/** Pointer to the player object, so we can easily display his health */
	Player * player;
	/** A health display pointer so we can create and remove health when necessary */
	Health * health;

	
public slots:
	void handleTimer();

};

#endif // GAMEWINDOW_H