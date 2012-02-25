#include "traynotificationwidget.h"
#ifdef Q_OS_MAC
#include <Carbon/Carbon.h>
#endif

TrayNotificationWidget::TrayNotificationWidget()
{
    setWindowFlags(
                Qt::FramelessWindowHint |
                Qt::WindowSystemMenuHint |
                Qt::WindowStaysOnTopHint
                );

    // set the parent widget's background to translucent
    this->setAttribute(Qt::WA_TranslucentBackground, true);

//#ifdef Q_OS_MAC
//    winId(); // This call creates the OS window ID itself.
//    // qt_mac_window_for() doesn't

//    int setAttr[] = {
//        kHIWindowBitDoesNotHide, // Shows window even when app is hidden

//        kHIWindowBitDoesNotCycle, // Not sure if required, but not bad

//        kHIWindowBitNoShadow, // Keep this if you have your own design
//        // with cross-platform drawn shadows
//        0 };
//    int clearAttr[] = { 0 };
//    HIWindowChangeAttributes(qt_mac_window_for(this), setAttr, clearAttr);
//#endif

    // create a display widget for displaying child widgets
    QWidget* displayWidget = new QWidget;
    displayWidget->setGeometry(0, 0, this->width(), this->height());
    displayWidget->setStyleSheet("QWidget { background-color: rgba(0, 0, 0, 75%); border-width: 2px; border-style: solid; border-radius: 5px; border-color: #555555; }");
    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(displayWidget);
    setLayout(layout);
    show();

    timeout = new QTimer(this);
    connect(timeout, SIGNAL(timeout()), this, SLOT(fadeOut()));
    timeout->start(3000);
}

void TrayNotificationWidget::fadeOut()
{
    emit deleted(this);
    this->hide();
    //this->deleteLater();
}

