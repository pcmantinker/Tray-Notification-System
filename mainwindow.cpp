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
    QIcon *icon = new QIcon(":/icons/info.png");
    QPixmap pixmap = icon->pixmap(64,64);
    TrayNotificationWidget* trayNotification = new TrayNotificationWidget(pixmap, "Test message", "Here is some information");
    tnm->append(trayNotification);
}
