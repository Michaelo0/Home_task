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

    QFile pFile(":/passwords.txt");
    pFile.open(QIODevice::ReadOnly);
    QTextStream in(&pFile);
    QString line = in.readAll();
    while (!in.atEnd())
    {

        QString str=in.readLine();

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
//QHash<QString,QString>::iterator it;
//for(it=hash.begin();it=hash.end();++it)
//{
//    ui->listWidget->addItem(it.key()+" "+it.value());
//}
ui->textEdit->setPlainText(line);
QTextCursor cursor = ui->textEdit->textCursor();
cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);
}

void Form::on_pushButton_clicked()
{


    QFile  file(":/passwords.txt");

        QTextStream stream(&file);

file.open(QIODevice::QIODevice::WriteOnly);
    QString s=ui->lineEdit->text();
    QString s2=ui->lineEdit_2->text();
    hash.insert(s,s2);



//        for(it=hash.begin();it=hash.end();++it)
//        {
//            stream<< s + " " + s2 + "\n" ;
//        }




    while (!stream.atEnd())
    {
        qDebug()<<stream.readLine();
    }

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->listWidget->addItem(s);
file.close
        ();
}

