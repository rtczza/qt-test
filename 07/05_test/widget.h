#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QProgressDialog>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    QProgressDialog *my_progress;
    QTimer *t;
    int step;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void my_cancel();

    void my_timeout();


private:
    Ui::Widget *ui;
};
#endif // WIDGET_H