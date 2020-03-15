#include "widget.h"
#include "ui_widget.h"
#include <QTime>
#include <QDebug>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    Init();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::Init()
{
    num = 0;
    btstring = "";

    //产生种子
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    //产生随机数
    num = qrand()%100;

    connect(ui->bt1, &QPushButton::clicked, this, &dealbt);
    connect(ui->bt2, &QPushButton::clicked, this, &dealbt);
    connect(ui->bt3, &QPushButton::clicked, this, &dealbt);
    connect(ui->bt4, &QPushButton::clicked, this, &dealbt);
    connect(ui->bt5, &QPushButton::clicked, this, &dealbt);
    connect(ui->bt6, &QPushButton::clicked, this, &dealbt);
    connect(ui->bt7, &QPushButton::clicked, this, &dealbt);
    connect(ui->bt8, &QPushButton::clicked, this, &dealbt);
    connect(ui->bt9, &QPushButton::clicked, this, &dealbt);
    connect(ui->bt0, &QPushButton::clicked, this, &dealbt);

}


void Widget::dealbt()
{
   QPushButton *bt = (QPushButton *)this->sender();
   if(bt == NULL)
       return ;

   QString text = bt->text();
   QString msg;

   if(btstring.length() <1){
       btstring.append(text);
   }else if(btstring.length() == 1)
   {
        btstring.append(text);
        qDebug() << btstring << btstring.toInt();
        int v1 = btstring.toInt();

        if(v1 < num){
            msg.append("猜小了！");
        }else if(v1 == num){
            msg.append("猜对了！");
            num = qrand()%100;
        }else{
            msg.append("猜大了！");
        }
        ui->textEdit->setText(msg);
   }else{
       btstring.clear();
       btstring.append(text);
    }
    ui->lcdNumber->display(btstring);
}
