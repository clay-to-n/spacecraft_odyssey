#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
#include <QListWidget>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QKeyEvent>
#include <ostream>
#include "gamewindow.h"


#define WINDOW_MAX_X 250
#define WINDOW_MAX_Y 350

/**
  This class is the main window in which all other elements of the program reside in.
  */
class GameWindow;

class MainWindow : public QWidget {
    Q_OBJECT
    
public:
    /** Default constructor which constructs the main window, which consists of a "gameboard" surrounded by buttons, forms for input, and a list view for error messages and cheat function output.
    */
    explicit MainWindow();
    /** Destructor */
    ~MainWindow();
    
private:

    QGraphicsScene *scene;
    QVBoxLayout *gameLayout;
    QVBoxLayout *consoleLayout;
    GameWindow *gameView;
    QLineEdit *playerName;
    QRadioButton *normalMode;
    QRadioButton *invincibleMode;
    QListWidget *messageDisplay;
    void keyPressEvent(QKeyEvent *e );
    void keyReleaseEvent(QKeyEvent *e );
 


public slots:
    
    void startGame();
    void pauseGame();
    void quitGame();

};



#endif // MAINWINDOW_H

