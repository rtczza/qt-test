#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSpacerItem>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

      QGridLayout *gridLayout_2;
      QSpacerItem *verticalSpacer;
      QSpacerItem *horizontalSpacer_2;
      QGridLayout *gridLayout;
      QHBoxLayout *horizontalLayout;
      QLabel *label;
      QLineEdit *lineEdit;
      QHBoxLayout *horizontalLayout_2;
      QLabel *label_2;
      QLineEdit *lineEdit_2;
      QHBoxLayout *horizontalLayout_3;
      QPushButton *pushButton;
      QPushButton *pushButton_2;
      QSpacerItem *horizontalSpacer;
      QSpacerItem *verticalSpacer_2;

      void cancel();
      void login();
       QString name = "adams";
       QString password = "qwer";

};
#endif // WIDGET_H
