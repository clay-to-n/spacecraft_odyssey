#include "mainwindow.h"


MainWindow::MainWindow()  
{
    scene = new QGraphicsScene();
    gameLayout = new QVBoxLayout();
    consoleLayout = new QVBoxLayout();

    //For gameView    
    gameView = new GameWindow();
    gameView->setMainWindow(this);
    gameView->view->setFixedSize(482, 582);
    gameLayout->addWidget(gameView->view);
    gameView->error = new QLineEdit("Enter a name, a gamemode, and press Play");
    consoleLayout->addWidget(gameView->error);

    //For Start / Stop buttons, use GHBoxLayout
    QPushButton *startButton = new QPushButton("Start / Pause");
    QPushButton *quitButton = new QPushButton("Quit");
    QVBoxLayout *buttonLayout = new QVBoxLayout;
    buttonLayout->addWidget(startButton);
    buttonLayout->addWidget(quitButton);
    connect(startButton, SIGNAL(pressed()), this, SLOT(startGame()));
    connect(quitButton, SIGNAL(pressed()), this, SLOT(quitGame()));

    //For Player Name input
    playerName = new QLineEdit;
    QFormLayout *paramLayout = new QFormLayout;
    paramLayout->addRow(tr("&Name:  "), playerName);

    //For Normal Mode and Invincible Mode Buttons
    normalMode = new QRadioButton("&Normal Mode", this);
    invincibleMode = new QRadioButton("&Invincible Mode", this);
    QVBoxLayout *modeLayout = new QVBoxLayout;
    modeLayout->addWidget(normalMode);
    modeLayout->addWidget(invincibleMode);

    //For Radio Buttons + Start / Stop Buttons
    QHBoxLayout *modeButtonLayout = new QHBoxLayout;
    modeButtonLayout->addLayout(modeLayout);
    modeButtonLayout->addLayout(buttonLayout);

    //This sets the size of the window and gives it a title
    this->setFixedSize( WINDOW_MAX_X*2, WINDOW_MAX_Y*2+40 );
    this->setWindowTitle( "SpaceCraft Odyssey!!!");

    QVBoxLayout *vertLayout = new QVBoxLayout;
    vertLayout->addLayout(gameLayout);
    vertLayout->addLayout(consoleLayout);
    vertLayout->addLayout(paramLayout);
    vertLayout->addLayout(modeButtonLayout);

    this->setLayout(vertLayout);

}


MainWindow::~MainWindow()
{

}

/** Starts the game by creating a board based on user input.  Sends the board to the gameView class to implement gameplay.
 */
void MainWindow::startGame()
{
    gameView->startGame();
    setFocus();
}

/** Starts the game by creating a board based on user input.  Sends the board to the gameView class to implement gameplay.
 */
void MainWindow::pauseGame()
{
    gameView->error->setText("Game is paused.");
}

/** Ends the game by calling qApp's quit function.  Closes the window.
 */
void MainWindow::quitGame()
{
    qApp->quit();
}