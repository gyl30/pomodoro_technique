#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSystemTrayIcon>
#include <QTimer>
#include <QSpinBox>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT

   public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override = default;

   public:
    void closeEvent(QCloseEvent *event) override;
    void hideEvent(QHideEvent *event) override;
   private slots:
    void startTimer();
    void stopTimer();
    void showTrayNotification();
    void tray_clicked(QSystemTrayIcon::ActivationReason);

   private:
    QTimer *timer_ = nullptr;
    QSystemTrayIcon *tray_ = nullptr;
    QSpinBox *time_spinbox_ = nullptr;
    QPushButton *start_button_ = nullptr;
};
#endif    // WIDGET_H
