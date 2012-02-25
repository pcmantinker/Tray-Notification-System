#ifndef TRAYNOTIFICATIONMANAGER_H
#define TRAYNOTIFICATIONMANAGER_H

#include <QtCore>
#include "traynotificationwidget.h"

class TrayNotificationManager : public QObject
{
    Q_OBJECT
signals:

public slots:
    void removeFirst(TrayNotificationWidget *widget);

public:
    TrayNotificationManager(QWidget *parent);
    ~TrayNotificationManager();
    void append(TrayNotificationWidget *widget);

private:
    QWidget* m_parent;
    QList<TrayNotificationWidget*>* notificationWidgets;
    int m_deltaX;
    int m_deltaY;
    int m_startX;
    int m_startY;
    int m_width;
    int m_height;
    bool m_up;
    int m_onScreenCount;
};

#endif // TRAYNOTIFICATIONMANAGER_H
