#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tnm = new TrayNotificationManager(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionShow_Notification_Widget_triggered()
{
    TrayNotificationWidget* trayNotification = new TrayNotificationWidget();
    tnm->append(trayNotification);
}
