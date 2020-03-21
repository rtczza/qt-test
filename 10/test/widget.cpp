#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPixmap>
#include <QPen>
#include <QPalette>
#include <QDebug>

//调试第一个程序标志位
#define test_1 0

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

#if test_1
    this->bt1 = new QPushButton(this);
    bt1->setText("Add");
    bt1->setMinimumSize(100, 60);

    this->bt2 = new QPushButton(this);
    bt2->setText("Dec");
    bt2->setMinimumSize(100, 60);

    connect(bt1, &QPushButton::clicked, this, &Widget::addslot);
    connect(bt2, &QPushButton::clicked, this, &Widget::decslot);
#endif

    setPalette(QPalette(Qt::white)); //设置窗口为白色背景
    setAutoFillBackground(true);

    step = 100;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::addslot()
{
    step += 20;
    this->update(); //更新界面
}


void Widget::decslot()
{
    step -= 20;
    this->update();
}



void Widget::paintEvent(QPaintEvent *)
{
#if test_1
 /* Qt帮助中的例程 */
//    QPainter painter(this);
//    painter.setPen(Qt::blue);
//    painter.setFont(QFont("Arial", 30));
//    painter.drawText(rect(), Qt::AlignCenter, "Qt");


    //使用图来画
    QPainter painter(this);
    painter.drawPixmap(0,0,this->width(), this->height(), QPixmap(":my_image/image/Penguins.jpg"));

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

     bt1->move(width()/2-50, height()*3/4);
     bt2->move(width()/2+50, height()*3/4);

#else


    QPainter my_painter(this); //创建QPainter对象
    my_painter.setRenderHint(QPainter::Antialiasing);
    my_painter.setRenderHint(QPainter::TextAntialiasing);

    int W = this->width(); // 绘图区宽度
    int H = this->height();// 绘图区高度
    QRect my_rect(W/4, H/4, W/2, H/2); //中间区域矩形框
//设置画笔
    QPen my_pen;
    my_pen.setWidth(3); //线宽
    my_pen.setColor(Qt::red); //划线颜色
    my_pen.setStyle(Qt::SolidLine); //线的样式，实线 虚线等
    my_pen.setCapStyle(Qt::FlatCap); //线端点样式
    my_painter.setPen(my_pen);

    QPixmap my_picture(":my_image/image/Koala.jpg");

//设置画刷
    QBrush my_brush;
   // my_brush.setColor(Qt::yellow); //画刷颜色
    my_brush.setStyle(Qt::SolidPattern);//画刷填充样式
    my_brush.setTexture(my_picture);
    my_painter.setBrush(my_brush);

//径向渐变
    QRadialGradient my_radial(W/2, H/2, qMax(W/8, H/8), W/2, H/2);
    my_radial.setColorAt(0, Qt::green);
    my_radial.setColorAt(1, Qt::blue);
    my_radial.setSpread(QGradient::ReflectSpread);//设置延展方式

//    线性渐变
#if 0
    QLinearGradient my_linear(my_rect.left(), my_rect.top(), //对角线
                              my_rect.right(), my_rect.bottom());
#else
    QLinearGradient my_linear(my_rect.left(), my_rect.top(),  // 从左到右
                              my_rect.right(), my_rect.top());
#endif

    my_linear.setColorAt(0, Qt::blue); //起点颜色
    my_linear.setColorAt(0.5, Qt::green);//中间点颜色
    my_linear.setColorAt(1, Qt::red);//终点颜色
    my_linear.setSpread(QGradient::ReflectSpread);//展布模式
//    my_linear.setSpread(QGradient::PadSpread);
//    my_linear.setSpread(QGradient::RepeatSpread);


//    圆锥渐变
    QConicalGradient my_conical(W/2, H/2, 45);
    my_conical.setColorAt(0, Qt::yellow);
    my_conical.setColorAt(0.5, Qt::blue);
    my_conical.setColorAt(1, Qt::red);


//绘图

//    选择一种渐变
//    my_painter.setBrush(my_radial);
//    my_painter.setBrush(my_linear);
    my_painter.setBrush(my_conical);

//    my_painter.drawRect(my_rect); // 设置的矩形大小
    my_painter.drawRect(this->rect()); //当前窗口的大小，填充更大区域，会有延展效果

#endif



}

