#include "widget.h"
#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QFont buttonFont("Times", 10, QFont::Bold);
    QPushButton * button = new QPushButton("Button1",this);
    button->setMinimumSize(200,100);
    button->setFont(buttonFont);
    connect(button,&QPushButton::clicked,[=]()
    {
        qDebug() << "Button clicked";
    });

    QPushButton * button2 = new QPushButton("Button2",this);
    button2->setMinimumSize(200,100);
    button2->setFont(buttonFont);
    button2->move(205,0);
    connect(button2,&QPushButton::pressed,[=](){
        qDebug() << "Button pressed";
    });
    connect(button2,&QPushButton::released,[=](){
        qDebug() << "Button released";
    });
}

Widget::~Widget()
{
}

