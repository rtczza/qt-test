#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->lineEdit_2->setEchoMode(QLineEdit::Password);

//    this->set

}

Widget::~Widget()
{
    delete ui;
}

//取消按钮
void Widget::on_pushButton_clicked()
{
    qDebug() << "close()";
    this->close();
}

//登录按钮
void Widget::on_pushButton_2_clicked()
{
    QString Name = ui->lineEdit->text();
    QString Password = ui->lineEdit_2->text();
    bool flag = 1;

    if(Name != this->name)
    {
        flag = 0;
        qDebug() << "用户名错误 ！" ;
    }
    if(Password != this->password)
    {
        flag = 0;
        qDebug() << "密码错误 ！";
    }
    if(flag)
    {
        qDebug() << "登录成功 ！";
        this->close();
    }
}
