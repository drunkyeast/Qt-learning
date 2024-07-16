#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
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


void Widget::on_pushButton_clicked()
{
//    ui->stackedWidget->setCurrentIndex(1);
//    QTimer* timer = new QTimer(this);
//    timer->setSingleShot(true); // 计时器只触发一次, 如何理解? 答:不用手动stop, 但是不会被自动析构..
//    timer->start(3000);
//    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->setCurrentIndex(1); // 切换到 loadingPage

    QTimer* timer = new QTimer(this);
    timer->setSingleShot(true); // 计时器只触发一次

    // 连接计时器的超时信号到槽函数
    connect(timer, &QTimer::timeout, this, [this, timer]() {
        ui->stackedWidget->setCurrentIndex(0); // 切换回 loginPage
        timer->deleteLater(); // 计时器不会自动析构，所以在这里删除它
    });

    timer->start(3000); // 启动计时器，3秒后触发
}
