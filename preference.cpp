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

#include "preference.h"
#include "ui_preference.h"
#include <QComboBox>
#include <QRadioButton>
#include <QPalette>

Preference::Preference(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Preference)
{
    ui->setupUi(this);
    buttonGroup = new QButtonGroup(this); // button group becomes a child of Preference
    buttonGroup->addButton(ui->radioButton24Hr); // groups radioButton24Hr together
    buttonGroup->addButton(ui->radioButton12Hr); // groups radionButton12Hr together
    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(onAccepted())); // creates a connect for the Ok and cancel button
}

Preference::~Preference()
{
    delete ui;
}


void Preference::onAccepted()
{
    QSettings settings("CMPS2212 GUI Programming","Jahmur Digital Clock"); // QSettings object created

    settings.setValue("Color",ui->colorBox->currentIndex()); // it sets the value of the color to an index

    if(ui->radioButton24Hr->isChecked()) // checks if the 24Hr radio button was selected
        settings.setValue("DigiClock","radioButton24Hr"); // change to appropriate time format
    else if(ui->radioButton12Hr->isChecked()) // checks if the 12Hr radio was selected
        settings.setValue("DigiClock","radioButton12Hr"); // change to appropriate time format
}
