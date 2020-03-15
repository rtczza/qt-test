#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QColorDialog>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

//about
void Widget::on_pushButton_clicked()
{
    QMessageBox::about(this, "关于", "作者：嘿嘿嘿 ！");
}

 //    information
void Widget::on_pushButton_2_clicked()
{
     QMessageBox::StandardButton ret =  QMessageBox::information(this, "信息", "嘿嘿嘿",
                             QMessageBox::Yes | QMessageBox::YesToAll
                             |QMessageBox::Ignore |QMessageBox::Cancel
                              |QMessageBox::NoToAll, QMessageBox::Cancel);

     if(ret == QMessageBox::Yes){
         qDebug() << "QMessageBox::Yes";
     }else if(ret == QMessageBox::YesToAll){
         qDebug() << "QMessageBox::YesToAll";
     }else if(ret == QMessageBox::Ignore){
         qDebug() << "QMessageBox::Ignore";
     }else if(ret == QMessageBox::Cancel){
         qDebug() << "QMessageBox::Cancel";
     }else if(ret == QMessageBox::NoToAll){
         qDebug() << "QMessageBox::NoToAll";
     }
}

  //warning
void Widget::on_pushButton_3_clicked()
{
    QMessageBox::StandardButton ret = QMessageBox::warning(this,"警告", "嘿嘿嘿",
                              QMessageBox::Yes | QMessageBox::YesToAll
                              |QMessageBox::Ignore |QMessageBox::Cancel
                              |QMessageBox::NoToAll, QMessageBox::Cancel);

    if(ret == QMessageBox::Yes){
        qDebug() << "QMessageBox::Yes";
    }else if(ret == QMessageBox::YesToAll){
        qDebug() << "QMessageBox::YesToAll";
    }else if(ret == QMessageBox::Ignore){
        qDebug() << "QMessageBox::Ignore";
    }else if(ret == QMessageBox::Cancel){
        qDebug() << "QMessageBox::Cancel";
    }else if(ret == QMessageBox::NoToAll){
        qDebug() << "QMessageBox::NoToAll";
    }
}

// set color
void Widget::on_pushButton_4_clicked()
{
    const QColor color = QColorDialog::getColor(Qt::blue,
                         this, "Select Color", QColorDialog::ShowAlphaChannel);

    if(color.isValid()){
        QPalette lable_palette = ui->label->palette();
        lable_palette.setColor(QPalette::WindowText, color);
        ui->label->setPalette(lable_palette);
    }
}
