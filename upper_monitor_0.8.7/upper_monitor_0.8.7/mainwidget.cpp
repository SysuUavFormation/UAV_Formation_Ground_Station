#include <QtWidgets>

#include "mainwidget.h"
#include "serialportpage.h"
#include "mappage.h"
#include "statuspage.h"



MainWidget::MainWidget()
{
    contentsWidget = new QListWidget;
    contentsWidget->setViewMode(QListView::IconMode);
    contentsWidget->setIconSize(QSize(80, 40));
    contentsWidget->setMovement(QListView::Static);
    contentsWidget->setFixedWidth(90);
    contentsWidget->setFrameStyle(QFrame::Panel);
    contentsWidget->setFrameShadow(QFrame::Raised);
    contentsWidget->setMidLineWidth(1);
    contentsWidget->viewport()->setAutoFillBackground(false);

    pagesWidget = new QStackedWidget;
    pagesWidget->addWidget(new SerialportPage);
    pagesWidget->addWidget(new MapPage);
    pagesWidget->addWidget(new StatusPage);

    createIcons();
    contentsWidget->setCurrentRow(0);

    QHBoxLayout *horizontalLayout = new QHBoxLayout(this);
    horizontalLayout->addWidget(contentsWidget);
    horizontalLayout->addWidget(pagesWidget);
    horizontalLayout->setStretchFactor(contentsWidget, 1);
    horizontalLayout->setStretchFactor(pagesWidget, 20);

    setWindowTitle(tr("Upper Monitor"));
}

void MainWidget::createIcons()
{
    QListWidgetItem *serialportButton = new QListWidgetItem(contentsWidget);
    serialportButton->setIcon(QIcon(":/images/configuration_icon.png"));
    serialportButton->setText(tr("串口配置"));
    serialportButton->setTextAlignment(Qt::AlignHCenter);
    serialportButton->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *mapButton = new QListWidgetItem(contentsWidget);
    mapButton->setIcon(QIcon(":/images/map_icon.png"));
    mapButton->setText(tr("地图"));
    mapButton->setTextAlignment(Qt::AlignHCenter);
    mapButton->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *statusButton = new QListWidgetItem(contentsWidget);
    statusButton->setIcon(QIcon(":/images/status_icon.png"));
    statusButton->setText(tr("状态"));
    statusButton->setTextAlignment(Qt::AlignCenter);
    statusButton->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    connect(contentsWidget,
            SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),
            this, SLOT(changePage(QListWidgetItem*,QListWidgetItem*)));
}

void MainWidget::changePage(QListWidgetItem *current, QListWidgetItem *previous)
{
    if (!current)
        current = previous;

    pagesWidget->setCurrentIndex(contentsWidget->row(current));
}

MainWidget::~MainWidget()
{

}
