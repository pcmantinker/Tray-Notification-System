#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include "traynotificationmanager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void closeEvent(QCloseEvent *);
    
private slots:
    void on_actionShow_Notification_Widget_triggered();

private:
    Ui::MainWindow *ui;
    TrayNotificationManager *tnm;
};

#endif // MAINWINDOW_H
