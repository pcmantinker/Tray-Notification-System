#include <QScreen>

#include "traynotificationwidget.h"

TrayNotificationWidget::TrayNotificationWidget(QPixmap pixmapIcon, QString headerText, QString messageText) : QWidget(0)
{
    setWindowFlags(
        #ifdef Q_OS_MAC
            Qt::SubWindow | // This type flag is the second point
        #else
            Qt::Tool |
        #endif
            Qt::FramelessWindowHint |
            Qt::WindowSystemMenuHint |
            Qt::WindowStaysOnTopHint
        );
    setAttribute(Qt::WA_NoSystemBackground, true);
    // set the parent widget's background to translucent
    setAttribute(Qt::WA_TranslucentBackground, true);

    //setAttribute(Qt::WA_ShowWithoutActivating, true);

    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    // create a display widget for displaying child widgets
    QWidget* displayWidget = new QWidget;
    displayWidget->setGeometry(0, 0, this->width(), this->height());
    displayWidget->setStyleSheet(".QWidget { background-color: rgba(0, 0, 0, 75%); "
    "border-width: 1pt; border-style: solid; border-radius: 10pt; border-color: #555555; } "
    ".QWidget:hover { background-color: rgba(68, 68, 68, 75%); border-width: 2pt; border-style: solid; border-radius: 10pt; border-color: #ffffff; }");

	int zoom_app = qApp->primaryScreen()->logicalDotsPerInch() / 96.0;
	zoom_app /= devicePixelRatio();

	QLabel* icon = new QLabel;
    icon->setPixmap(pixmapIcon);
	icon->setMaximumSize(32* zoom_app, 32* zoom_app);
    QLabel* header = new QLabel;



	header->setMaximumSize(225 * zoom_app, 50 * zoom_app);
    header->setWordWrap(true);
    header->setText(headerText);
    header->setStyleSheet("QLabel { color: #ffffff; font-weight: bold; font-size: 12pt; }");
    QLabel* message = new QLabel;
	message->setMaximumSize(225* zoom_app, 100* zoom_app);
    message->setWordWrap(true);
    message->setText(messageText);
    message->setStyleSheet("QLabel { color: #ffffff; font-size: 10pt; }");
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
	this->deleteLater();
}

