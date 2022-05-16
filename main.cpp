/*
 * Name: Jahmur Lopez
 * Student ID: 2015112808
 * Class: Graphical User Interface
 * Title: Digital Clock
 * Due Date: 16/02/2022
 * Due Time: 11:59 pm
 * Lectures: Thiana Vasquez
 * Class Section: 1
*/
#include "jahmurdigiclock.h"
#include "preference.h"
#include <QApplication>
#include <QSettings>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setApplicationName("Jahmur Digital Clock"); // sets the name of the application
    QCoreApplication::setOrganizationName("CMPS2212 GUI Programming"); // sets the name of the organization
    JahmurDigiClock w;
    Preference p;
    w.show(); // display Jahmur Digi Clock
    return a.exec();
}
