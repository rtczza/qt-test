#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPixmap>
#include <QPen>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    step = 100;
}

Widget::~Widget()
{
    delete ui;
}


void Widget::paintEvent(QPaintEvent *)
{
 /* Qt帮助中的例程 */
//    QPainter painter(this);
//    painter.setPen(Qt::blue);
//    painter.setFont(QFont("Arial", 30));
//    painter.drawText(rect(), Qt::AlignCenter, "Qt");


    //使用图来画
    QPainter painter(this);
    painter.drawPixmap(0,0,this->width(), this->height(), QPixmap("../Desert.jpg"));

    //用笔画
    QPen *pen_one = new QPen(Qt::CustomDashLine);
    pen_one->setColor(Qt::blue);
    pen_one->setWidth(10);

    painter.setPen(*pen_one);
    painter.drawLine(QPoint(0,0), QPoint(this->width(), this->height()));


    //第二条线
    QPen pen_two;
    pen_two.setStyle(Qt::DotLine);
    pen_two.setColor(Qt::red);
    pen_two.setWidth(5);

    painter.setPen(pen_two);
    painter.drawLine(QPoint(0, this->height()), QPoint(this->width(), 0));

    //画个矩形
    pen_two.setColor(Qt::green);//此时修改颜色无效。需要停止使用画笔。
    painter.drawRect(100, 100, 200, 200);

    //画个椭圆
    painter.drawEllipse(QPoint(this->width()/2, this->height()/2), 50, 100);


    //用画刷画
    QBrush brush_one;
    brush_one.setStyle(Qt::CrossPattern);
    brush_one.setColor(Qt::green);

    painter.setBrush(brush_one);

//      static
           const   QPointF points[4] = { //此处不能用 static 修饰，不然不会做修改
         QPointF(this->width()/2-step, this->height()/2-step),
         QPointF(this->width()/2+step, this->height()/2-step),
         QPointF(this->width()/2+step, this->height()/2+step),
         QPointF(this->width()/2-step, this->height()/2+step)
     };
     painter.drawPolygon(points, 4);
}

void Widget::on_pushButton_clicked()
{
    step += 20;
    this->update(); //更新界面
}


void Widget::on_pushButton_2_clicked()
{
    step -= 20;
    this->update();
}
