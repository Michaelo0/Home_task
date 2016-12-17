#include "form.h"
#include "ui_form.h"
#include <QHash>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

   // qDebug() << QString::fromUtf8(a);


}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{


    QFile  file(":/passwords.txt");
    file.open(QIODevice::WriteOnly|QIODevice::WriteOnly);


    if(file.open(QIODevice::ReadOnly ))
    {
        QTextStream stream(&file);
        QString str;

        while (!stream.atEnd())
        {

            str=stream.readLine();
            qDebug()<<str;
            char* ptr=NULL;

            ptr=strtok(str.toLocal8Bit().data()," ");
            QString s,s2;
            int i=0;
            while (ptr)
            {
                i++;

                if (i<=1)
                    s=ptr;
                else
                    s2=ptr;
            }
            hash.insert(s,s2);



        }

    }


    QString s=ui->lineEdit->text();
    QString s2=ui->lineEdit_2->text();
    hash.insert(s,s2);


    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&file);

        for(;it!=hash.end();++it)
        {
            stream<< s + " " + s2 + "\n" ;
        }

    }
if (file.open(QIODevice::ReadOnly))
{
    QTextStream stream(&file);
    while (!stream.atEnd())
    {
        qDebug()<<stream.readLine();
    }
}
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->listWidget->addItem(s);
file.close();
}

