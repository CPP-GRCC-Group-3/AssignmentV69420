#include "editwindow.h"
#include "ui_editwindow.h"
#include <string>
#include <iostream>
#include <QIODevice>
#include <QFile>

using namespace std;

extern QStringList strings;

editWindow::editWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editWindow)
{
    ui->setupUi(this);
    ui->quoteList->addItems(strings);
}

editWindow::~editWindow()
{
    delete ui;
}

void editWindow::on_exitButton2_clicked()
{
    this->hide();
}

void editWindow::on_popButton_clicked()
{
 string quote = this->ui->addQuote->toPlainText().toStdString();
 QString qQuote = QString::fromStdString(quote);

 strings.append(qQuote);

 ui->quoteList->clear();
 ui->quoteList->addItems(strings);
}

void editWindow::on_saveButton_clicked()
{
    QFile file("quotes.txt");


    if (file.open(QIODevice::WriteOnly | QIODevice::Text)){

        QTextStream stream(&file);

        for (int i = 0; i < strings.length(); i++) {

            stream << strings[i] << '\n';
        }
    }

    file.close();
}
