#include <QApplication>
#include <QDialog>
#include <QLabel>
#include <QStyle>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include "message_box.h"

CustomMessageBox::CustomMessageBox(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("定时提醒");
    setFixedSize(300, 150);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    auto *label = new QLabel("运动时间到啦", this);
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-size: 18px; color: #333; padding: 10px;");

    // 添加确认按钮
    auto *confirm = new QPushButton("好的", this);
    confirm->setStyleSheet(
        "QPushButton {"
        "   background-color: #4CAF50;"
        "   color: white;"
        "   border-radius: 10px;"
        "   padding: 10px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #45a049;"
        "}"
        "QPushButton:pressed {"
        "   background-color: #388e3c;"
        "}");
    auto *layout = new QVBoxLayout(this);
    layout->addWidget(label);
    layout->addWidget(confirm);
    connect(confirm, &QPushButton::clicked, this, &QDialog::accept);
}

void CustomMessageBox::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        click_pos_ = e->pos();
    }
}
void CustomMessageBox::mouseMoveEvent(QMouseEvent *e)
{
    if ((e->buttons() & Qt::LeftButton) != 0U)
    {
        move(e->pos() + pos() - click_pos_);
    }
}
