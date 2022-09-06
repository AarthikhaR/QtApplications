#include "mainwindow.h"
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QPushButton * button = new QPushButton(this);
    button->setText("Click Me");
    button->move(200,200);
    connect(button,&QPushButton::clicked,[=](){

        //hard way
        /*
        QMessageBox message;
        message.setMinimumSize(300,200);
        message.setWindowTitle("Message Title");
        message.setText("Something happened");
        message.setInformativeText("Do you want to do something about it ?");
        message.setIcon(QMessageBox::Critical);
        message.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        message.setDefaultButton(QMessageBox::Cancel);
        int ret = message.exec();
        */
        //Critical Message
        /*
        int ret = QMessageBox::critical(this,"Message Title","Something happened.Do you want to do soemthing about it ? ",QMessageBox::Ok | QMessageBox::Cancel);
        */
        /*
        //Information Message
        int ret = QMessageBox::information(this,"Message Title","Something happened.Do you want to do soemthing about it ? ",QMessageBox::Ok | QMessageBox::Cancel);
        */
        /*
        //Question Message
        int ret = QMessageBox::question(this,"Message Title","Something happened.Do you want to do soemthing about it ? ",QMessageBox::Ok | QMessageBox::Cancel);
        */
        //Warning Message
        int ret = QMessageBox::warning(this,"Message Title","Something happened.Do you want to do soemthing about it ? ",QMessageBox::Ok | QMessageBox::Cancel);
        if( ret == QMessageBox :: Ok)
        {
            qDebug() << "User clicked on OK";
        }
        if( ret == QMessageBox :: Cancel)
        {
            qDebug() << "User clicked on CANCEL";
        }
    });
}

MainWindow::~MainWindow()
{
}

QSize MainWindow::sizehint() const
{
    return QSize(800,800);
}

