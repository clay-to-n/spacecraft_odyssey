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
#include <string>
#include <vector>
#include <fstream>
#include <QGraphicsSimpleTextItem>
#include "gamewindow.h"
#include "scoreentry.h"

using namespace std;

#define WINDOW_MAX_X 250
#define WINDOW_MAX_Y 350

/** This class is the main window in which all other elements of the program reside in.
  */
class GameWindow;

class MainWindow : public QWidget {
    Q_OBJECT
    
public:
    /** Default constructor which constructs the main window, which consists of a "gameView" followed by inputs and buttons to start the game.
    */
    explicit MainWindow();
    /** Destructor */
    ~MainWindow();
    bool started;
    GameWindow *gameView;
    
private:
    QString name;
    QGraphicsScene *scene;
    QVBoxLayout *gameLayout;
    QVBoxLayout *consoleLayout;
    QLineEdit *playerName;
    QRadioButton *normalMode;
    QRadioButton *invincibleMode;
    QListWidget *messageDisplay;
    vector<ScoreEntry> ScoreList;
    void keyPressEvent(QKeyEvent *e );
    void keyReleaseEvent(QKeyEvent *e );
    void loadScores();
 
public slots:
    void startPauseGame();
    void quitGame();

};



#endif // MAINWINDOW_H

