#ifndef TRAYNOTIFICATIONWIDGET_H
#define TRAYNOTIFICATIONWIDGET_H

#include <QtWidgets>

class TrayNotificationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TrayNotificationWidget(QPixmap pixmapIcon, QString headerText, QString messageText);

private:
    QTimer* timeout;

signals:
    void deleted(TrayNotificationWidget*);

public slots:
   void fadeOut();

};

#endif // TRAYNOTIFICATIONWIDGET_H
