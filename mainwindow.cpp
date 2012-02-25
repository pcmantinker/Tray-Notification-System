#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "traynotificationwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionShow_Notification_Widget_triggered()
{
    TrayNotificationWidget* trayNotification = new TrayNotificationWidget();
    trayNotification->show();
    this->setFocus(Qt::ActiveWindowFocusReason);
    this->activateWindow();
    this->raise();
}
