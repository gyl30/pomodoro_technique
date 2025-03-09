#ifndef MESSAGE_BOX_H
#define MESSAGE_BOX_H

#include <QApplication>
#include <QDialog>
#include <QPoint>
#include <QMouseEvent>

class CustomMessageBox : public QDialog
{
    Q_OBJECT

   public:
    explicit CustomMessageBox(QWidget *parent = nullptr);
    ~CustomMessageBox() override = default;

   public:
    void mousePressEvent(QMouseEvent *e) override;
    void mouseMoveEvent(QMouseEvent *e) override;

   private:
    QPoint click_pos_;
};

#endif
