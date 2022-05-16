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
#ifndef JAHMURDIGICLOCK_H
#define JAHMURDIGICLOCK_H

#include <QMainWindow>
#include <QLCDNumber>
#include <QToolBar>
#include <QPoint>

QT_BEGIN_NAMESPACE
namespace Ui { class JahmurDigiClock; }
QT_END_NAMESPACE

class JahmurDigiClock : public QMainWindow
{
    Q_OBJECT

public:
    JahmurDigiClock(QWidget *parent = nullptr);
    ~JahmurDigiClock(); // destructor created

protected:
    void mouseReleaseEvent(QMouseEvent *e); // keeps tabs if the mouse click was released
    void mousePressEvent(QMouseEvent *e); // keeps tabs if the mouse was pressed
    void mouseMoveEvent(QMouseEvent *e); // keeps track of mouse movement
    void closeEvent(QCloseEvent *e); // keeps tabs if the application is close/open

private slots:
    void updateTime(); // updates time from the O.S.
    void showContextMenu(const QPoint &pos); // shows drop down menu
    void showPreference(); // display the preference QDialog
    void close(); // to close application

private:
    Ui::JahmurDigiClock *ui; // digitcal clock application
    QLCDNumber * lcdNumber; // private object created for lcd widget
    QPoint  m_mousePos; // private object created for QPoint class
    void setColor(); // sets the appropriate color for the clock

};
#endif // JAHMURDIGICLOCK_H
