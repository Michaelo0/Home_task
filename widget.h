#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "form.h"

namespace Ui
{
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    void Widget::load_pwd_from_file();
    ~Widget();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    Form* form;
    QString password;

};

#endif // WIDGET_H
