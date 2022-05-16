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
#ifndef PREFERENCE_H
#define PREFERENCE_H

#include <QDialog>
#include <QSettings>
#include <QButtonGroup>
#include <QComboBox>

namespace Ui {
class Preference;
}

class Preference : public QDialog
{
    Q_OBJECT

public:
    explicit Preference(QWidget *parent = nullptr);
    ~Preference();


private:
    Ui::Preference *ui;
    QButtonGroup * buttonGroup;

private slots:
    void onAccepted();

};

#endif // PREFERENCE_H
