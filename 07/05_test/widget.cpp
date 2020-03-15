#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QColorDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <QDir>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    my_progress = NULL;
    step = 0;
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

//set font
void Widget::on_pushButton_5_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont("Times", 12), this);
    if (ok) {
                 // font is set to the font the user selected
            ui->label->setFont(font);
    } else {
                 // the user canceled the dialog; font is set to the initial
                 // value, in this case Times, 12.
     }
}

// input dialog
void Widget::on_pushButton_6_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                               tr("User name:"), QLineEdit::Normal,
                                               QDir::home().dirName(), &ok);
          if (ok && !text.isEmpty())
              ui->label->setText(text);

    int i = QInputDialog::getInt(this, tr("QInputDialog::getInteger()"),
                                             tr("Percentage:"), 25, 0, 100, 1, &ok);
    if (ok)
            ui->label_2->setText(tr("%1%").arg(i));

}

//QProgressDialog
void Widget::on_pushButton_7_clicked()
{
    if(NULL == my_progress){
        step = 0;
        my_progress = new QProgressDialog(this);

        my_progress->setRange(0,100);
        connect(my_progress, &QProgressDialog::canceled,
                    this, &Widget::my_cancel);

        t = new  QTimer(this);
        connect(t, &QTimer::timeout,
                 this, &Widget::my_timeout);
        t->start(100);

       }

}

// 取消进度条
void Widget::my_cancel()
{
    t->stop();
    delete my_progress;
    my_progress = NULL;
}

//定时器定时任务
void Widget::my_timeout()
{
    my_progress->setValue(step);
    step++;
    if(step >my_progress->maximum()){
        t->stop();
        step = 0;
    }
}















