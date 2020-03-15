#include "widget.h"
#include <QApplication>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    if (this->objectName().isEmpty())
                this->setObjectName(QString::fromUtf8("Widget"));
            this->resize(444, 371);
            gridLayout_2 = new QGridLayout(this);
            gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
            verticalSpacer = new QSpacerItem(20, 119, QSizePolicy::Minimum, QSizePolicy::Expanding);

            gridLayout_2->addItem(verticalSpacer, 0, 1, 1, 1);

            horizontalSpacer_2 = new QSpacerItem(80, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

            gridLayout_2->addItem(horizontalSpacer_2, 1, 0, 1, 1);

            gridLayout = new QGridLayout();
            gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
            horizontalLayout = new QHBoxLayout();
            horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
            label = new QLabel(this);
            label->setObjectName(QString::fromUtf8("label"));

            horizontalLayout->addWidget(label);

            lineEdit = new QLineEdit(this);
            lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

            horizontalLayout->addWidget(lineEdit);


            gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

            horizontalLayout_2 = new QHBoxLayout();
            horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
            label_2 = new QLabel(this);
            label_2->setObjectName(QString::fromUtf8("label_2"));

            horizontalLayout_2->addWidget(label_2);

            lineEdit_2 = new QLineEdit(this);
            lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
            lineEdit_2->setEnabled(true);
            lineEdit_2->setEchoMode(QLineEdit::Normal);

            horizontalLayout_2->addWidget(lineEdit_2);


            gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

            horizontalLayout_3 = new QHBoxLayout();
            horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
            pushButton = new QPushButton(this);
            pushButton->setObjectName(QString::fromUtf8("pushButton"));

            horizontalLayout_3->addWidget(pushButton);

            pushButton_2 = new QPushButton(this);
            pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

            horizontalLayout_3->addWidget(pushButton_2);


            gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);


            gridLayout_2->addLayout(gridLayout, 1, 1, 1, 1);

            horizontalSpacer = new QSpacerItem(79, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

            gridLayout_2->addItem(horizontalSpacer, 1, 2, 1, 1);

            verticalSpacer_2 = new QSpacerItem(20, 118, QSizePolicy::Minimum, QSizePolicy::Expanding);

            gridLayout_2->addItem(verticalSpacer_2, 2, 1, 1, 1);

            QWidget::setTabOrder(lineEdit, lineEdit_2);
            QWidget::setTabOrder(lineEdit_2, pushButton);
            QWidget::setTabOrder(pushButton, pushButton_2);


            this->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
            label->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
            label_2->setText(QApplication::translate("Widget", "\345\257\206\347\240\201\357\274\232  ", nullptr));
            pushButton->setText(QApplication::translate("Widget", "\345\217\226\346\266\210", nullptr));
            pushButton_2->setText(QApplication::translate("Widget", "\347\231\273\345\275\225", nullptr));



            connect(pushButton, &QPushButton::clicked, this, &cancel);
            connect(pushButton_2,&QPushButton::clicked, this,&login);

}

Widget::~Widget()
{
}


void Widget::cancel()
{
    this->close();
}

void Widget::login()
{
    QString Name = lineEdit->text();
    QString Password = lineEdit_2->text();
    bool flag = 1;

    if(Name != this->name)
    {
        flag = 0;
        qDebug() << "用户名错误 ！" ;
    }
    if(flag && (Password != this->password))
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
