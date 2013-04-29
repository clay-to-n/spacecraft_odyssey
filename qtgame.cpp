#include <QtGui/QApplication>
#include "mainwindow.h"

/** @mainpage CSCI 102 Qt Game - SpaceCraft Odyssey: '99 Prime Edition
 @section purpose Purpose/Overview
 A top-down 2D shooter in which the user controls a ship and fights enemies to rack up massive points.
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
