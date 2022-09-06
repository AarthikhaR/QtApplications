#include "rockwidget.h"
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>

RockWidget::RockWidget(QWidget *parent) : QWidget(parent)
{
//    setWindowTitle("Rock Widget Here");
    QLabel * label = new QLabel("This is my label",this);

    //Add a styled widget and move it around
    QPalette label1Palette;
    label1Palette.setColor(QPalette::Window,Qt::yellow);
    label1Palette.setColor(QPalette::WindowText,Qt::blue);

    QFont label1Font("Times",20,QFont::Bold);

    QLabel *label1 = new QLabel(this);
    label1->setText("My coloured Label");
    label1->setFont(label1Font);
    label1->setPalette(label1Palette);
    label1->setAutoFillBackground(true);
    label1->move(50,50);

    //Add another label
    QFont label2Font("Times",30,QFont::Bold);

    QPalette label2Palette;
    label2Palette.setColor(QPalette::Window,Qt::blue);
    label2Palette.setColor(QPalette::WindowText,Qt::red);

    QLabel *label2 = new QLabel(this);
    label2->setText("Another Label");
    label2->move(50,120);
    label2->setFont(label2Font);
    label2->setPalette(label2Palette);

    //Add a button and connect to slot
    QFont buttonFont("Times",25,QFont::Bold);
    QPushButton * button = new QPushButton(this);
    button->setText("Click Me");
    button->setFont(buttonFont);
    button->move(100,250);
    connect(button,&QPushButton::clicked,this,&RockWidget::click);

}

void RockWidget::click()
{
    QMessageBox::information(this,"Message","You have clicked on my button");
    qDebug() << "Slot executed";
}

QSize RockWidget::sizeHint() const
{
    return QSize(500,500);
}


