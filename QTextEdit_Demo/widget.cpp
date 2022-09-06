#include "widget.h"
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setupUi();
    setFixedSize(400,400);
}

Widget::~Widget()
{
}

void Widget::setupUi()
{
    QFont labelFont("Times",10,QFont::Bold);
    QLabel * mlabel = new QLabel("This is my text",this);
    mlabel->setFont(labelFont);
    mlabel->move(100,25);

    QTextEdit * textEdit = new QTextEdit(this);
    textEdit->move(70,55);
    /*
    //textChanged
    connect(textEdit,&QTextEdit::textChanged,[=]()
    {
        qDebug() << "Text Changed";
    });
    */
    /*
     * Copy
     * Paste
     * Undo
     * Redu
     * setHtml
     * setPlainText
    */
    //Copy,Cut and Paste
    QPushButton * copyButton = new QPushButton("Copy",this);
    copyButton->setMinimumSize(50,25);
    copyButton->move(10,250);
    connect(copyButton,&QPushButton::clicked,[=](){
        textEdit->copy();
    });

    QPushButton * cutButton = new QPushButton("Cut",this);
    cutButton->setMinimumSize(50,25);
    cutButton->move(110,250);
    connect(cutButton,&QPushButton::clicked,[=](){
        textEdit->cut();
    });

    QPushButton * pasteButton = new QPushButton("Paste",this);
    pasteButton->setMinimumSize(50,25);
    pasteButton->move(210,250);
    connect(pasteButton,&QPushButton::clicked,[=](){
        textEdit->paste();
    });

    //Undo Redo
    QPushButton * undoButton = new QPushButton("Undo",this);
    undoButton->setMinimumSize(50,25);
    undoButton->move(10,280);
    connect(undoButton,&QPushButton::clicked,[=](){
        textEdit->undo();
    });

    QPushButton * redoButton = new QPushButton("Redo",this);
    redoButton->setMinimumSize(50,25);
    redoButton->move(110,280);
    connect(redoButton,&QPushButton::clicked,[=](){
        textEdit->redo();
    });

    //Set text and HTML to the text edit
    QPushButton * plainTextButton = new QPushButton("Plain Text",this);
    plainTextButton->setMinimumSize(100,25);
    plainTextButton->move(10,310);
    connect(plainTextButton,&QPushButton::clicked,[=](){
        textEdit->setPlainText("Qt is used for developing graphical user interfaces (GUIs) and multi-platform applications that run on all major desktop platforms and most mobile or embedded platforms. Most GUI programs created with Qt have a native-looking interface, in which case Qt is classified as a widget toolkit.");
    });

    QPushButton * htmlButton = new QPushButton("Html",this);
    htmlButton->setMinimumSize(100,25);
    htmlButton->move(120,310);
    connect(htmlButton,&QPushButton::clicked,[=](){
        textEdit->setHtml("<h1>The city is Trichy</h1>");
    });

    //Grab text and html
    QPushButton * grabTextButton = new QPushButton("Grab Text",this);
    grabTextButton->setMinimumSize(100,25);
    grabTextButton->move(10,340);
    connect(grabTextButton,&QPushButton::clicked,[=](){
        qDebug() << "The plain text inside the text edit is : " << textEdit->toPlainText();
    });

    QPushButton * grabhtmlButton = new QPushButton("Grab Text",this);
    grabhtmlButton->setMinimumSize(100,25);
    grabhtmlButton->move(120,340);
    connect(grabhtmlButton,&QPushButton::clicked,[=](){
        qDebug() << "The html text inside the text edit is : " << textEdit->toHtml();
    });

}

