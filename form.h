#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QFile>
#include <QByteArray>
#include <QIODevice>
#include <QDebug>
#include <QTextStream>
namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);


    ~Form();

private slots:
    void on_pushButton_clicked();



    //void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::Form *ui;
    QHash<QString, QString> passwords_info;
void loadPwdFromFile();

};

#endif // FORM_H
