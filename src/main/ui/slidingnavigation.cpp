#include "slidingnavigation.h"
#include "ui_slidingnavigation.h"
#include "src/mylistbuddy.h"
#include "ui/featruedialog.h"
#include "qdebug.h"

SlidingNavigation::SlidingNavigation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SlidingNavigation)
{
    ui->setupUi(this);
    ui->lw_features->setViewMode(QListView::ListMode);   //设置显示模式为列表模式
    QSize *qListWidgetItemSize = new QSize(this->width(),50);
    for (int i = 0; i<99;i++) {
        MyListBuddy *buddy =new MyListBuddy(this,qListWidgetItemSize);
        buddy->pFeaturesStr->setText("ccc");
        buddy->pDetailsStr->setText("lalala");

        QListWidgetItem *item = new QListWidgetItem(ui->lw_features);
        item->setSizeHint(*qListWidgetItemSize);//设置宽度、高度
        ui->lw_features->setItemWidget(item, buddy); //将buddy赋给该newItem
        ui->lw_features->addItem(item);

    }

    connect(ui->lw_features, SIGNAL(itemEntered(QListWidgetItem *)),this, SLOT(on_lw_features_itemClicked(QListWidgetItem *)));

}

SlidingNavigation::~SlidingNavigation()
{
    delete ui;
}

void SlidingNavigation::on_lw_features_itemClicked(QListWidgetItem *item)
{   qDebug() << "on_lw_features_itemClicked" ;
    FeatrueDialog *dialog = new FeatrueDialog();
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->setWindowTitle(tr("feature 1  name"));
    dialog->setData(item);
    dialog->show();
}
