#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->listWidget->setSelectionMode(QAbstractItemView::MultiSelection);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_addItemButton_clicked()
{
    ui -> listWidget ->addItem("MyItem");

}

void Widget::on_deleteButton_clicked()
{
    //Delete item : use takeItem
    ui -> listWidget -> takeItem(ui->listWidget->currentRow());
}

void Widget::on_SelectedItemButton_clicked()
{
    //Get the list of selected items
    QList<QListWidgetItem * > list = ui->listWidget->selectedItems();

    for( int i=0;i<list.count();i++)
    {
        qDebug() << "Selected item : "<<list.at(i)->text() << ", row number id : " << ui->listWidget->row(list.at(i));
    }
}
