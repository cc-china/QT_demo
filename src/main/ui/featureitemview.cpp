#include "featureitemview.h"
#include "ui_featureitemview.h"

FeatureItemView::FeatureItemView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FeatureItemView)
{
    ui->setupUi(this);
    QTableWidget *features_tableWidget = ui->features_tableWidget;
    //设置表头
    QStringList header;
    header<<"Month"<<"Description";
    features_tableWidget->setHorizontalHeaderLabels(header);
    features_tableWidget->setRowCount(10); //设置行数
    features_tableWidget->setColumnCount(2); //设置列数
    /*设置列名*/
    QStringList headers;
    for(int i = 1;i<=10;i++){
        headers.append("列名1");
    }
    //features_tableWidget->setHorizontalHeaderLabels(headers);
    /*给单元格添加内容*/
    for(int i = 0;i<10;i++){
        addItemContent(i,0,"ccc",features_tableWidget);
        addItemContent(i,1,"ccc",features_tableWidget);
    }

    /*去掉每行的行号 列号*/
    QHeaderView *verticalHeader = features_tableWidget->verticalHeader();
    verticalHeader->setHidden(true);
    QHeaderView *horizontalHeader = features_tableWidget->horizontalHeader();
    horizontalHeader->setHidden(true);
}

FeatureItemView::~FeatureItemView()
{
    delete ui;
}

void FeatureItemView::addItemContent(int row, int column, QString content,QTableWidget *features_tableWidget)
{
    QTableWidgetItem *item = new QTableWidgetItem (content);
    features_tableWidget->setItem(row, column, item);
}
