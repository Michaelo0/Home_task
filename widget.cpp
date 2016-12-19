#include "widget.h"
#include "ui_widget.h"
#include "QFile"
#include "QMessageBox"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QFile file(":/masterpassword.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);

    password = in.readAll();
qDebug()<<password;
    file.close();

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{

    QString pwd = ui->lineEdit->text();

    if(pwd != password) return;
    form = new Form();
    this->hide();
    form->show();
    QString pwd2 = ui->lineEdit->text();

}

void Widget::on_pushButton_2_clicked()
{
    QFile file(":/masterpassword.txt");
    file.open(QIODevice::WriteOnly);
    QTextStream stream(&file);
    QString s=ui->lineEdit_2->text();
    QString s2=ui->lineEdit_3->text();

    if(s==s2)
    {

        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        stream<<s;
    QMessageBox::information(this,QString::fromStdString("Создание пароля"),QString::fromStdString("Пароль успешно создан"));

    }
    else
QMessageBox::critical(this,QString::fromStdString("Ошибка"),QString::fromStdString("Пароли не совпадают"));
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    file.close();
}


