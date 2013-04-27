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
#include <vector>
#include "mainwindow.h"
#include "player.h"

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
	//void setBoard(Board *b);
	void setMainWindow(MainWindow *mainWindow);
	void startGame();
	void moveObject();
	/** Vector of GUITiles which will be displayed. */
	QLineEdit *error;
	/** Pointer to the board class that is being used. */
	static const int xSize_ = 482;
	static const int ySize_ = 582;

private:
	int timerCount;
	//int tileSize;
	int timerX;
	int timerY;
	MainWindow * mainWindow_;
	QPixmap * backgroundImage;
	QPixmap * playerImage;
	QPixmap * longRange1Image;
	QPixmap * closeRange1Image;
	QPixmap * boss1Image;
	Player * player;
	/** Pointer to a GUITile that will be animated. */
	
	/** Vector of QBrushes to use to color the tiles. */
	/** Pointer to a QTimer to be used for animation. */
	QTimer* timer_;
	
public slots:
	void handleTimer();

};

#endif // GAMEWINDOW_H