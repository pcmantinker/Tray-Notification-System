#include "traynotificationmanager.h"

TrayNotificationManager::TrayNotificationManager(QWidget *parent)
{
    m_parent = parent;
    notificationWidgets = new QList<TrayNotificationWidget*>();
    QDesktopWidget* desktopWidget = QApplication::desktop();
    QRect clientRect = desktopWidget->availableGeometry();
    m_width = 350;
    m_height = 130;
    m_onScreenCount = 0;
#ifdef Q_WS_MACX
    m_startX = clientRect.width() - m_width;
    m_startY = 10;
    m_up = false;
#endif

#ifdef Q_WS_WIN
    m_startX = clientRect.width() - m_width - 5;
    m_startY = clientRect.height() - m_height - 5;
    m_up = true;
#endif

    m_deltaX = 0;
    m_deltaY = 0;


    //QTimer* hideTimer = new QTimer;
    //connect(hideTimer, SIGNAL(timeout()), this, SLOT(removeFirst()));
    //hideTimer->start(3000);
}

TrayNotificationManager::~TrayNotificationManager()
{
    delete notificationWidgets;
}

void TrayNotificationManager::append(TrayNotificationWidget* widget)
{
    connect(widget, SIGNAL(deleted(TrayNotificationWidget*)), this, SLOT(removeFirst(TrayNotificationWidget*)));
    qDebug() << "Count: " + QVariant(notificationWidgets->count()).toString();
    if(notificationWidgets->count() < 3)
    {
        qDebug() << "Before: " + QVariant(m_deltaY).toString();

        if(notificationWidgets->count() > 0)
        {
            if(m_up)
                m_deltaY += -130;
            else
                m_deltaY += 130;
        }

        if(notificationWidgets->count() == 0)
            m_deltaY = 0;

        qDebug() << "After: " + QVariant(m_deltaY).toString();
    }
    else
    {
        m_deltaY = 0;
    }

    widget->setGeometry(m_startX + m_deltaX, m_startY + m_deltaY, m_width, m_height);
    notificationWidgets->append(widget);
    m_parent->activateWindow();
}

void TrayNotificationManager::removeFirst(TrayNotificationWidget *widget)
{
    int i = notificationWidgets->indexOf(widget, 0);
    qDebug() << "Count: " + QVariant(notificationWidgets->count()).toString();
    qDebug() << "Index: " + QVariant(i).toString();

    if(notificationWidgets->count() > 0)
    {
        notificationWidgets->takeAt(i)->deleteLater();
        //delete widget;
        qDebug() << "Removing TrayNotificationWidget";
    }
}
