#include "traynotificationwidget.h"

TrayNotificationWidget::TrayNotificationWidget()
{
    setWindowFlags(
                Qt::FramelessWindowHint |
                Qt::WindowSystemMenuHint |
                Qt::WindowStaysOnTopHint
                );

    // set the parent widget's background to translucent
    this->setAttribute(Qt::WA_TranslucentBackground, true);

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
}

