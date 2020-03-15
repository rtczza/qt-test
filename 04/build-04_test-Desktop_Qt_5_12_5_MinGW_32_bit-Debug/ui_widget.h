/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QLCDNumber *lcdNumber;
    QTextEdit *textEdit;
    QPushButton *bt1;
    QPushButton *bt2;
    QPushButton *bt3;
    QPushButton *bt4;
    QPushButton *bt5;
    QPushButton *bt6;
    QPushButton *bt7;
    QPushButton *bt8;
    QPushButton *bt9;
    QPushButton *bt0;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(524, 307);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lcdNumber = new QLCDNumber(Widget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setLineWidth(2);

        gridLayout->addWidget(lcdNumber, 0, 0, 1, 4);

        textEdit = new QTextEdit(Widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 0, 4, 1, 1);

        bt1 = new QPushButton(Widget);
        bt1->setObjectName(QString::fromUtf8("bt1"));

        gridLayout->addWidget(bt1, 1, 0, 1, 1);

        bt2 = new QPushButton(Widget);
        bt2->setObjectName(QString::fromUtf8("bt2"));

        gridLayout->addWidget(bt2, 1, 1, 1, 1);

        bt3 = new QPushButton(Widget);
        bt3->setObjectName(QString::fromUtf8("bt3"));

        gridLayout->addWidget(bt3, 1, 2, 1, 1);

        bt4 = new QPushButton(Widget);
        bt4->setObjectName(QString::fromUtf8("bt4"));

        gridLayout->addWidget(bt4, 1, 3, 1, 1);

        bt5 = new QPushButton(Widget);
        bt5->setObjectName(QString::fromUtf8("bt5"));

        gridLayout->addWidget(bt5, 1, 4, 1, 1);

        bt6 = new QPushButton(Widget);
        bt6->setObjectName(QString::fromUtf8("bt6"));

        gridLayout->addWidget(bt6, 2, 0, 1, 1);

        bt7 = new QPushButton(Widget);
        bt7->setObjectName(QString::fromUtf8("bt7"));

        gridLayout->addWidget(bt7, 2, 1, 1, 1);

        bt8 = new QPushButton(Widget);
        bt8->setObjectName(QString::fromUtf8("bt8"));

        gridLayout->addWidget(bt8, 2, 2, 1, 1);

        bt9 = new QPushButton(Widget);
        bt9->setObjectName(QString::fromUtf8("bt9"));

        gridLayout->addWidget(bt9, 2, 3, 1, 1);

        bt0 = new QPushButton(Widget);
        bt0->setObjectName(QString::fromUtf8("bt0"));

        gridLayout->addWidget(bt0, 2, 4, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        bt1->setText(QApplication::translate("Widget", "1", nullptr));
        bt2->setText(QApplication::translate("Widget", "2", nullptr));
        bt3->setText(QApplication::translate("Widget", "3", nullptr));
        bt4->setText(QApplication::translate("Widget", "4", nullptr));
        bt5->setText(QApplication::translate("Widget", "5", nullptr));
        bt6->setText(QApplication::translate("Widget", "6", nullptr));
        bt7->setText(QApplication::translate("Widget", "7", nullptr));
        bt8->setText(QApplication::translate("Widget", "8", nullptr));
        bt9->setText(QApplication::translate("Widget", "9", nullptr));
        bt0->setText(QApplication::translate("Widget", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
