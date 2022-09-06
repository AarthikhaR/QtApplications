#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->miniontextlabel->move(100,30);

    //Add an image to the second label
    QPixmap minionPixmap("://images/minion.png");

    ui->imageLabel->move(0,70);
    ui->imageLabel->setPixmap(minionPixmap.scaled(400,400));
}

Widget::~Widget()
{
    delete ui;
}

