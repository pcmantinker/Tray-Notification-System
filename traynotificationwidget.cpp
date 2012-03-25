#include "traynotificationwidget.h"

TrayNotificationWidget::TrayNotificationWidget(QPixmap pixmapIcon, QString headerText, QString messageText)
{
    setWindowFlags(
                Qt::FramelessWindowHint |
                Qt::WindowStaysOnTopHint |
                Qt::SubWindow
#ifdef Q_WS_WIN
                | Qt::Tool // only make a tool window if in Windows
#endif
                );

#ifdef Q_WS_X11
    setAttribute(Qt::WA_NoSystemBackground, true);
#endif
    // set the parent widget's background to translucent
    setAttribute(Qt::WA_TranslucentBackground, true);
    setAttribute(Qt::WA_ShowWithoutActivating, true);


    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    // create a display widget for displaying child widgets
    QWidget* displayWidget = new QWidget;
    displayWidget->setGeometry(0, 0, this->width(), this->height());
    displayWidget->setStyleSheet(".QWidget { background-color: rgba(0, 0, 0, 75%); border-width: 2px; border-style: solid; border-radius: 10px; border-color: #555555; }");

    QLabel* icon = new QLabel;
    icon->setPixmap(pixmapIcon);
    icon->setMaximumSize(64, 64);
    icon->setMinimumSize(32, 32);
    QLabel* header = new QLabel;
    header->setMaximumSize(225, 50);
    header->setWordWrap(true);
    header->setText(headerText);
    header->setStyleSheet("QLabel { color: #ffffff; font-weight: bold; font-size: 14px; }");
    QLabel* message = new QLabel;
    message->setMaximumSize(225, 100);
    message->setWordWrap(true);
    message->setText(messageText);
    message->setStyleSheet("QLabel { color: #ffffff; font-size: 12px; }");
    QHBoxLayout* displayMainLayout = new QHBoxLayout;
    displayMainLayout->addWidget(icon);
    QVBoxLayout* vl = new QVBoxLayout;
    vl->addWidget(header);
    vl->addWidget(message);
    displayMainLayout->addLayout(vl);
    displayWidget->setLayout(displayMainLayout);

    QHBoxLayout* containerLayout = new QHBoxLayout;
    containerLayout->addWidget(displayWidget);
    setLayout(containerLayout);
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

