#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>

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

// open file
void Widget::on_pushButton_2_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,"openfile test",
                                                    "../", tr("ALL(*.*)"));
    if(fileName.isEmpty()){
        QMessageBox::warning(this,"警告", "无文件打开");
        return ;
    }else{
         ui->textEdit->setText(fileName);
    }

    my_file->setFileName(fileName);
    bool ret = my_file->open(QIODevice::ReadWrite);
    if(!ret){
        QMessageBox::warning(this,"警告", "文件打开失败");
        return ;
    }

    //QFile直接读取

/*
    while(!my_file->atEnd()){
        //read 函数 QByteArray 转为 QString 类型
 //       QByteArray  ba = my_file->read(256);
 //       QString str = QString(ba);

        //read 函数 char* 转为 QString 类型
//        char buf[1024] = {0};
//        memset(buf, 0, 1024);
//        my_file->read(buf,1024);
//        QString str = QString(buf);

        //readline函数
       QByteArray  ba =  my_file->readLine(1024);
       QString str = QString(ba);

       //追加到textedit中
       ui->textEdit->append(str);
    }
*/
/*
    //readall函数
     QByteArray  ba = my_file->readAll();
     QString str = QString(ba);
     ui->textEdit->append(str);
 */

//    文本流形式读取（支持大文本文件读取）
    //使用QTextStream 后，操作对象就从my_file 改为 text了。
    QTextStream text(my_file);
    while(!text.atEnd()){
        QString str = text.readAll(); //QTextStream 中，readAll的返回值直接就是QString
        ui->textEdit->append(str);
    }

    my_file->close();

}

//open dir
void Widget::on_pushButton_3_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("opendir test"),
                                                     "../",
                                                     QFileDialog::ShowDirsOnly
                                                     | QFileDialog::DontResolveSymlinks);
    if(dir.isEmpty()){
        QMessageBox::warning(this,"警告", "无目录打开");
        return ;
    }else{
         ui->textEdit_2->setText(dir);
    }
}

void Widget::Init()
{
    my_file = new QFile(this);
}

//save file
void Widget::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,"savefile test",
                                                    "../", tr("Text(*.cpp *.h)"));
    if(fileName.isEmpty()){
        QMessageBox::warning(this,"警告", "无文件打开");
        return ;
    }

    my_file->setFileName(fileName);
    bool ret = my_file->open(QIODevice::WriteOnly | QIODevice::Text);
    if(!ret){
        QMessageBox::warning(this,"警告", "文件打开失败");
        return ;
    }

    // QFile形式直接读取
    // 把textedit中的内容保存到文件中
   qint64 ret_int =  my_file->write(ui->textEdit_3->toPlainText().toLocal8Bit());
   if(-1 == ret_int) {
        my_file->close();
        return ;
   }

    //文本流形式读取（支持大文本文件读取）
    QTextStream save_file(my_file);
    QString str = ui->textEdit_3->toPlainText().toLocal8Bit();
    save_file << str;

    my_file->close();
}


