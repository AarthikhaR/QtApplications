#include "widget.h"
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QDebug>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //First Name
    QLabel * firstNameLabel = new QLabel("First Name",this);
    firstNameLabel -> setMinimumSize(70,50);
    firstNameLabel->move(10,10);

    QLineEdit *firstNameLineEdit = new QLineEdit(this);
    firstNameLineEdit->setMinimumSize(200,50);
    firstNameLineEdit->move(100,10);

    //Last Name
    QLabel * LastNameLabel = new QLabel("Last Name",this);
    LastNameLabel -> setMinimumSize(70,50);
    LastNameLabel->move(10,70);

    QLineEdit *LastNameLineEdit = new QLineEdit(this);
    LastNameLineEdit->setMinimumSize(200,50);
    LastNameLineEdit->move(100,70);

    //City
    QLabel * cityLabel = new QLabel("City Name",this);
    cityLabel -> setMinimumSize(70,50);
    cityLabel->move(10,130);

    QLineEdit *cityNameLineEdit = new QLineEdit(this);
    cityNameLineEdit->setMinimumSize(200,50);
    cityNameLineEdit->move(100,130);

    //Grab Data button
    QFont buttonFont("Times",20,QFont::Bold);
    QPushButton *GrabButton = new QPushButton("Grab Data",this);
    GrabButton->move(80,190);
    GrabButton->setFont(buttonFont);

    connect(GrabButton,&QPushButton::clicked,[=](){
        QString firstName = firstNameLineEdit->text();
        QString lastName = LastNameLineEdit->text();
        QString city = cityNameLineEdit->text();

        if(!firstName.isEmpty() && !lastName.isEmpty() && !city.isEmpty())
        {
            //If neither field is empty we fall here
            qDebug() << "First Name : " << firstName;
            qDebug() << "Last Name : " << lastName;
            qDebug() << "City : " << city;
        }
        else
        {
            qDebug() << "One field is empty!";
        }

    });

    //Respond to signals from QLineEdits

    /*
    //cursorPositionChanged signal
    connect(firstNameLineEdit,&QLineEdit::cursorPositionChanged,[=]()
    {
        qDebug() << "The current cursor position is : "<<firstNameLineEdit->cursorPosition();
    });
    */
    /*
    //editingFinished()=>This signal is emitted when the Return or Enter key is pressed or the line edit loses focus.
    connect(firstNameLineEdit,&QLineEdit::editingFinished,[=]()
    {
        qDebug() << "Editing Finished";
    });
    */
    /*
    //returnPressed
    connect(firstNameLineEdit,&QLineEdit::returnPressed,[=]()
    {
        qDebug() << "Return Pressed!";
    });
    */
    /*
    //selectionChanges
    connect(firstNameLineEdit,&QLineEdit::selectionChanged,[=]()
    {
        qDebug() << "Selection Changed";
    });
    */
    /*
    //textChanged
    connect(firstNameLineEdit,&QLineEdit::textChanged,[=]()
    {
        qDebug() << "Text Changed to " << firstNameLineEdit->text();
    });
    */
    //textEdited
    connect(firstNameLineEdit,&QLineEdit::textEdited,[=]()
    {
        qDebug() << "Text Edited and Changed to " << firstNameLineEdit->text();
    });

    //Change text in QLineEdit programmatically
//    LastNameLineEdit->setText("Last Name is");
    //Hint text
    firstNameLineEdit->setPlaceholderText("First Name");
    LastNameLineEdit->setPlaceholderText("Last Name");
    cityNameLineEdit->setPlaceholderText("City");

}

Widget::~Widget()
{
}

