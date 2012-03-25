#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tnm = new TrayNotificationManager(this);
    //tnm->setMaxTrayNotificationWidgets(3);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete tnm;
}

void MainWindow::closeEvent(QCloseEvent *)
{
    QApplication::quit();
}

void MainWindow::on_actionShow_Notification_Widget_triggered()
{
    QIcon* icon = new QIcon(":/online.png");
    TrayNotificationWidget* trayNotification = new TrayNotificationWidget(icon->pixmap(32, 32), "Test", "This is a test message.");
    tnm->append(trayNotification);
}
