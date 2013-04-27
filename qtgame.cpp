#include <QtGui/QApplication>
#include "mainwindow.h"

/** @mainpage CSCI 102 Qt Puzzle - PA4
 @section purpose Purpose/Overview
 A simple puzzle game created using Qt.
 @section requirements Requirements
 How to call: Simply run ./game_cbrand
*/

/**
* Main function which calls QApplication and begins the program.
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    return a.exec();
}
