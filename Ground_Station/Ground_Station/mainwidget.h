#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "uav_link.h"

QT_BEGIN_NAMESPACE
class QListWidget;
class QListWidgetItem;
class QStackedWidget;
class UAV_Link;
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget();
    ~MainWidget();

public slots:
    void changePage(QListWidgetItem *current, QListWidgetItem *previous);

private:
    void createIcons();

    QListWidget *contentsWidget;
    QStackedWidget *pagesWidget;
    UAV_link *uav_link;
};

#endif // MAINWIDGET_H
