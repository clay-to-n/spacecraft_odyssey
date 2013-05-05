#include "mainwindow.h"


MainWindow::MainWindow()  
{
    started = false;
    scene = new QGraphicsScene();
    gameLayout = new QVBoxLayout();
    consoleLayout = new QVBoxLayout();

    //For gameView    
    gameView = new GameWindow();
    gameView->setMainWindow(this);
    gameView->view->setFixedSize(482, 582);
    gameLayout->addWidget(gameView->view);
    gameView->error = new QLineEdit("Enter a name, a gamemode, and press Start");
    consoleLayout->addWidget(gameView->error);

    //For Start / Stop buttons, use GHBoxLayout
    QPushButton *startButton = new QPushButton("Start / Pause");
    QPushButton *quitButton = new QPushButton("Quit Game");
    QVBoxLayout *buttonLayout = new QVBoxLayout;
    buttonLayout->addWidget(startButton);
    buttonLayout->addWidget(quitButton);
    connect(startButton, SIGNAL(pressed()), this, SLOT(startPauseGame()));
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
    this->setWindowTitle( "SpaceCraft Odyssey: '99 Prime Edition");

    QVBoxLayout *vertLayout = new QVBoxLayout;
    vertLayout->addLayout(gameLayout);
    vertLayout->addLayout(consoleLayout);
    vertLayout->addLayout(paramLayout);
    vertLayout->addLayout(modeButtonLayout);

    this->setLayout(vertLayout);
    loadScores();

}


MainWindow::~MainWindow()
{

}

/** Key Press Event to keep track of what the player is pressing
* @param e Standard key press pointer implementation
*/
void MainWindow::keyPressEvent(QKeyEvent *e )
{
    switch (e->key())
    {
        case Qt::Key_W:
            gameView->pressedW = true;
            break;

        case Qt::Key_A:
            gameView->pressedA = true;
            break;

        case Qt::Key_S:
            gameView->pressedS = true;
            break;

        case Qt::Key_D:
            gameView->pressedD = true;
            break;

        case Qt::Key_Space:
            gameView->pressedSpace = true;
            break;
    }
}

/** Key Release Event so that the game knows when keys are released
* @param e Standard key press pointer implementation
*/
void MainWindow::keyReleaseEvent(QKeyEvent *e )
{
    switch (e->key())
    {
        case Qt::Key_W:
            gameView->pressedW = false;
            break;

        case Qt::Key_A:
            gameView->pressedA = false;
            break;

        case Qt::Key_S:
            gameView->pressedS = false;
            break;

        case Qt::Key_D:
            gameView->pressedD = false;
            break;

        case Qt::Key_Space:
            gameView->pressedSpace = false;
            break;
    }
}

/** Loads the scores present in the scores.txt file*/
void MainWindow::loadScores()
{
    ScoreList.clear();
    ifstream fin;
    fin.open("scores.txt");
    string tempString;
    int tempScore;

    fin >> tempScore;
    while (fin != NULL)
    {
        fin.ignore(5, ' ');
        getline(fin, tempString);
        QString tempQString = QString::fromStdString(tempString);
        ScoreEntry tempEntry(tempQString, tempScore);
        ScoreList.push_back(tempEntry);
        fin >> tempScore;
    }

    gameView->ScoreList = &ScoreList;
}

/** Starts the game if the user has entered in their name and chosen a game mode.  If the game has already started, this button pauses it.  If the game is paused, this button resumes it.
*/
void MainWindow::startPauseGame()
{
    if (started == false && normalMode->isChecked() && playerName->text() != NULL)
    {
        gameView->playerName->setText(playerName->text());
        gameView->playerNameString = playerName->text();
        gameView->startGame();
        setFocus();
        started = true;
        return;
    }   
    if (started == false && invincibleMode->isChecked() && playerName->text() != NULL)
    {
        gameView->playerName->setText(playerName->text());
        gameView->playerNameString = playerName->text();
        gameView->startInvincibleGame();
        setFocus();
        started = true;
        return;
    }    
    if (started == true && gameView->timer->isActive())
    {
        gameView->error->setText("Game is paused.");
        gameView->timer->stop();
        return;
    }  
    if (started == true && !gameView->timer->isActive())
    {
        gameView->error->setText("Move using WASD keys.  Hold space to shoot.");
        setFocus();
        gameView->timer->start();
        return;
    }      

}

/** Ends the game by calling qApp's quit function.  Closes the window.*/
void MainWindow::quitGame()
{
    qApp->quit();
}