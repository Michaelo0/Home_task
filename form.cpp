#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    loadPwdFromFile();

}

Form::~Form()
{
    delete ui;
}


void Form::loadPwdFromFile()
{
   // QHash<QString, QString> passwords_info;
    QFile file("passwords.txt");
    if(file.open(QIODevice::ReadOnly)){
    QTextStream in(&file);
    QString raw_data = in.readAll();
    QStringList pwd_lines = raw_data.split(QRegExp("\n|/r/n"), QString::SkipEmptyParts);
       foreach(QString raw_line, pwd_lines)
         {
             QStringList line = raw_line.split(" ", QString::SkipEmptyParts);
             qDebug()<<line[0];
             passwords_info.insert(line[0], line[1]);
             ui->listWidget->addItem(line[0]);
         }
    }
    file.close();
}

void Form::on_pushButton_clicked()
{

    QString s=ui->lineEdit->text();
    QString s2=ui->lineEdit_2->text();
    passwords_info.insert(s,s2);
    QFile  file("passwords.txt");

        QTextStream out(&file);

file.open(QIODevice::WriteOnly|QFile::Text);

QHashIterator<QString,QString>i(passwords_info);
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

