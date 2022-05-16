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
#include "ui_jahmurdigiclock.h"
#include <QLCDNumber>
#include <QTimer>
#include <QString>
#include <QDateTime>
#include <QTimer>
#include <QMenu>
#include <QMouseEvent>
#include <QAction>
#include <QStatusBar>
#include <QSettings>
#include <QByteArray>
#include <QPalette>
#include "preference.h"
#include <QComboBox>


JahmurDigiClock::JahmurDigiClock(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::JahmurDigiClock)
{
    ui->setupUi(this);
    QTimer * timer = new QTimer(this); // allocated memory for QTimer object
    timer->start(1000); // let the timer start in milliseconds
    updateTime(); // explicit call function 'updateTime()'

    QSettings settings("CMPS2212 GUI Programming","Jahmur Digital Clock"); // settings object created

    setAttribute(Qt::WA_TranslucentBackground); // the background becomes translucent
    setWindowFlags(Qt::WindowStaysOnTopHint |  Qt::FramelessWindowHint | Qt::Tool); // the clock will become frameless
    this->setContextMenuPolicy(Qt::CustomContextMenu); // when the user request a context menu

    restoreGeometry(settings.value("MainGeometry").toByteArray()); // translate what was stored to the byte array
    restoreState(settings.value("MainState").toByteArray()); // translate what was stored to the byte array
    setColor();

    connect(this,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(showContextMenu(QPoint)));
    connect(this,SIGNAL(showPreference()),this,SLOT(setColor())); // connect function to create drop down menu and change
    connect(timer, &QTimer::timeout,this, &JahmurDigiClock::updateTime); // signal and slot created to display clock with actual time
}

JahmurDigiClock::~JahmurDigiClock()
{
    delete ui;
}


void JahmurDigiClock::mouseReleaseEvent(QMouseEvent *e)
{
   if(e->button() == Qt::RightButton) // checks if user right clicked the mouse
   {
       emit customContextMenuRequested(e->pos()); // emits the signal for conext menu
   }
   else
   {
       QMainWindow::mouseReleaseEvent(e); // recieve mouse release event
   }
}

void JahmurDigiClock::mousePressEvent(QMouseEvent *e)
{
  m_mousePos = e->pos(); // stores the position of the mouse
}

void JahmurDigiClock::mouseMoveEvent(QMouseEvent *e)
{
    this->move(e->globalPosition().toPoint() - m_mousePos); // translate the global position to the mouse
}

void JahmurDigiClock::closeEvent(QCloseEvent *e)
{
  QSettings settings; // QSettings object created
  settings.setValue("MainGeometry",saveGeometry()); // saves area of the clock that was last closed
  settings.setValue("MainState",saveState()); // saves the last settings of the clock before it was closed
  e->accept(); // sets the new values
}

void JahmurDigiClock::updateTime()
{
    QTime time = QTime::currentTime(); // gets the current time from Operating System
    QString currentTimeText;

    QSettings settings("CMPS2212 GUI Programming","Jahmur Digital Clock"); // QSettings object created

    if(settings.value("DigiClock") == "radioButton24Hr") // checks if the 24hr radio button was clicked
    {
        currentTimeText = time.toString("hh:mm:ss"); // update to the appropriate time format

    if((time.second() % 2) == 0) // controls the blinking of the colon ':'
    {
        currentTimeText[2] = ' ';
        currentTimeText[5] = ' ';
    }
    }else if(settings.value("DigiClock") == "radioButton12Hr") // checks if the 12hr radio button was clicked
    {
        currentTimeText = time.toString("h:mm:ss p"); // update to the appropriate time format
        if(time.second() % 2 == 0) // controls the blinking of the colon ':'
        {
            currentTimeText[2] = ' ';
            currentTimeText[5] = ' ';
        }
    }
    ui->lcdNumber->display(currentTimeText); // lets the ui directly update the current time to the LCD widget
}

void JahmurDigiClock::showContextMenu(const QPoint &pos)
{
    QMenu *contextMenu = new QMenu(); // QMenu object created
    contextMenu->addAction("Exit",this,SLOT(close())); // creates a drop down option for 'Exit'
    contextMenu->addAction("Preference",this,SLOT(showPreference())); // creates a drop down option for 'Preference'
    contextMenu->exec(mapToGlobal(pos)); // display the drop down menu
}

void JahmurDigiClock::showPreference()
{
  Preference * pDialog = new Preference(this); // child object of JahmurDigiClock created
  pDialog->setWindowTitle("JahmurDigiClock");
  pDialog->exec(); // display the QDialog
  setColor(); // explicit function call for setColor
}

void JahmurDigiClock::close()
{
  QCoreApplication::quit(); // Digital clock app close after right click
}

void JahmurDigiClock::setColor()
{
    QSettings settings("CMPS2212 GUI Programming","Jahmur Digital Clock"); // QSettings object was created
    QPalette colours; // QPalette object was created

    int comboColor = settings.value("Color").toInt(); // variable to store the color order of QComboBox
    switch(comboColor)
    {
      case 0: // checks if the color number was 0
        colours.setColor(QPalette::WindowText,Qt::black); // change color of lcdNumber to black
        break;

      case 1: // checks if the color number was 1
        colours.setColor(QPalette::WindowText,Qt::yellow); // change color of lcdNumber to yellow
        break;

      case 2: // checks if the color number was 2
        colours.setColor(QPalette::WindowText,Qt::green); // change color of lcdNumber to green
        break;

      case 3: // checks if the color number was 3
        colours.setColor(QPalette::WindowText,Qt::red); // change color of lcdNumber to red
        break;

      default:
        colours.setColor(QPalette::WindowText,Qt::black); // automatically sets the lcdNumber to black from start-up
        break;

    }
  ui->lcdNumber->setPalette(colours); // explicitly sets the appropriate color for lcdNumber from the UI
  this-> updateTime(); // let the function update its current time from the parent widget
}


