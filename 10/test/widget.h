#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void paintEvent(QPaintEvent *);

private slots:
    void addslot();
    void decslot();

private:
    Ui::Widget *ui;

    int step;

    QPushButton *bt1;
    QPushButton *bt2;
};
#endif // WIDGET_H
