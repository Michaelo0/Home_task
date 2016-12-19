#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    loadTextFile();


}

Form::~Form()
{
    delete ui;
}


void Form::loadTextFile()
{

    QFile file(":/passwords.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    QString raw_data = in.readAll();
       QStringList pwd_lines = raw_data.split(QRegExp("\n|/r/n"), QString::SkipEmptyParts);
       foreach(QString raw_line, pwd_lines)
         {
             QStringList line = raw_line.split(" ", QString::SkipEmptyParts);
             passwords_info.insert(line[0], line[1]);
         }


}

void Form::on_pushButton_clicked()
{


    QFile  file(":/passwords.txt");

        QTextStream out(&file);

file.open(QIODevice::QIODevice::WriteOnly);
    QString s=ui->lineEdit->text();
    QString s2=ui->lineEdit_2->text();
    hash.insert(s,s2);
QHashIterator<QString,QString>i(hash);
        while(i.hasNext())
        {
            i.next();
            out<<i.value()<<" "<<i.key()<<endl;

        }
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->listWidget->addItem(s);
file.flush();
file.close();

}

