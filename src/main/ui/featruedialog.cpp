#include "featruedialog.h"
#include "ui_featruedialog.h"
#include "qdebug.h"

#include <QHeaderView>
QTableWidget *features_tableWidget;

FeatrueDialog::FeatrueDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FeatrueDialog)
{
    ui->setupUi(this);
     features_tableWidget = ui->features_tableWidget;
     /*设置表格是否充满，即行末不留空*/
     features_tableWidget->horizontalHeader()->setStretchLastSection(true);
     /*设置tablewidget等宽*/
     features_tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

FeatrueDialog::~FeatrueDialog()
{
    delete ui;
}
void FeatrueDialog::addItemContent(int row, int column, QString content,QTableWidget *features_tableWidget,bool enableChange)
{
    QTableWidgetItem *item = new QTableWidgetItem (content);
    if(enableChange){

    }else{
       item->setFlags(item->flags() & ~Qt::ItemIsEnabled);
    }
    features_tableWidget->setItem(row, column, item);
    
}
void FeatrueDialog::setData(QListWidgetItem *item)
{
    QList<ControlItemModel> *mControlItemModelList = new QList<ControlItemModel>();
    QList<FieldItemModel> *mFieldItemModelList = new QList<FieldItemModel>();
    QList<DefaultItemModel> *mDefaultItemModelList = new QList<DefaultItemModel>();
    for (int i=0;i<3;i++) {
        DefaultItemModel *pDefaultItemModel = new DefaultItemModel();
        pDefaultItemModel->id=i;
        pDefaultItemModel->enableChange = true;
        pDefaultItemModel->name=QString("cc").append(i);
        mDefaultItemModelList->insert(i,*pDefaultItemModel);
    }
    for (int i = 0;i<2;i++) {
        FieldItemModel *pFieldItemModel = new FieldItemModel();
        pFieldItemModel->id = i;
        pFieldItemModel->enableChange = false;
        pFieldItemModel->name = QString("Field ").append(i).append(QString(" name"));
        pFieldItemModel->mDefaultList = *mDefaultItemModelList;
        mFieldItemModelList->insert(i,*pFieldItemModel);
    }
    for (int i = 0;i<2;i++) {
        ControlItemModel *pControlItemModel = new ControlItemModel();
        pControlItemModel->id = i;
        pControlItemModel->enableChange = false;
        pControlItemModel->name = QString("Control ").append(i).append(QString(" name"));
        pControlItemModel->mFieldList = *mFieldItemModelList;
        mControlItemModelList->insert(i,*pControlItemModel);
    }
    FeatureItemModel *pFeatureItemModel= new FeatureItemModel();
    pFeatureItemModel->name = QString("Feature ").append(1).append(QString(" name"));
    pFeatureItemModel->mControlList = *mControlItemModelList;
    initView(pFeatureItemModel);
}

void FeatrueDialog::initView(FeatureItemModel *pFeatureItemModel)
{
    //设置表头
    QStringList header;
    header<<"Month"<<"Description";
    features_tableWidget->setHorizontalHeaderLabels(header);
    features_tableWidget->setRowCount(18); //设置行数
    features_tableWidget->setColumnCount(2); //设置列数

    qint32 dataSetTableWeightNum = getDataSetTableWeight(pFeatureItemModel);
    qDebug() << "dataSetTableWeightNum" << dataSetTableWeightNum;

    /*设置列名*/
    QStringList headers;
    for(int i = 1;i<=dataSetTableWeightNum;i++){
        headers.append("列名1");
    }
    //features_tableWidget->setHorizontalHeaderLabels(headers);

     /*插入一行*/
//    int row = features_tableWidget->rowCount();
//    features_tableWidget->insertRow(row);
    /*合并单元格*/
    //features_tableWidget->setSpan(0, 0, 1, 2);
    //设置每行内容不可编辑
    //setFlags(ui->tableWidget->item(iRow, iColumn)->flags() & ~Qt::ItemIsEnabled);
    /*给单元格中增加图标*/
    //QTableWidgetItem *item = new QTableWidgetItem(QIcon("myImage.jpg"), NULL);  //只加入图标，没有字符串
//    QTableWidgetItem *item = new QTableWidgetItem(QIcon(":/triangle.jpg"), "control 1 name ");   //加入图标和字符串
//    features_tableWidget->setItem(0, 0, item);
//    addItemContent(1,0,"field 1 name",features_tableWidget);
//    addItemContent(1,1,"value1",features_tableWidget);
//    addItemContent(2,0,"",features_tableWidget);
//    addItemContent(2,1,"ccc",features_tableWidget);
//    addItemContent(3,1,"ccc",features_tableWidget);
//    addItemContent(4,0,"field 2 name",features_tableWidget);
//    addItemContent(4,1,"value1",features_tableWidget);
//    addItemContent(5,1,"ccc",features_tableWidget);
//    addItemContent(6,1,"ccc",features_tableWidget);

    /*合并单元格*/
//    features_tableWidget->setSpan(7, 0, 1, 2);
//    QTableWidgetItem *item7 = new QTableWidgetItem(QIcon(":/triangle.jpg"), "control 2 name ");   //加入图标和字符串
//    features_tableWidget->setItem(7, 0, item7);
//    addItemContent(8,0,"field 2 name",features_tableWidget);
//    addItemContent(8,1,"value1",features_tableWidget);
//    addItemContent(9,1,"ccc",features_tableWidget);
//    addItemContent(10,1,"ccc",features_tableWidget);
//    addItemContent(11,0,"field 2 name",features_tableWidget);
//    addItemContent(11,1,"value1",features_tableWidget);
//    addItemContent(12,1,"ccc",features_tableWidget);
//    addItemContent(13,1,"ccc",features_tableWidget);
//    for(int i = 0;i<10;i++){
//        addItemContent(i,0,"ccc",features_tableWidget);
//        addItemContent(i,1,"ccc",features_tableWidget);
//    }


    /*去掉每行的行号 列号*/
    QHeaderView *verticalHeader = features_tableWidget->verticalHeader();
    verticalHeader->setHidden(true);
    QHeaderView *horizontalHeader = features_tableWidget->horizontalHeader();
    horizontalHeader->setHidden(true);
}

qint32 FeatrueDialog::getDataSetTableWeight(FeatureItemModel *pFeatureItemModel)
{
    qint32 rowCount = 0;
    //rowCount = pFeatureItemModel->mControlList.size();
    QList<ControlItemModel> mControlList = pFeatureItemModel->mControlList;
    for (int i = 0; i<mControlList.size(); i++) {
        //control level
        //rowCount += mControlList[i].mFieldList.size();
        features_tableWidget->setSpan(rowCount,0,1,2);
        QTableWidgetItem *item = new QTableWidgetItem(QIcon(":/triangle.jpg"), mControlList[i].name);   //加入图标和字符串
        features_tableWidget->setItem(rowCount, 0, item);
        item->setFlags(item->flags() & ~Qt::ItemIsEnabled);
        rowCount++;
        QList<FieldItemModel> mFieldList = mControlList[i].mFieldList;
        for (int j = 0; j<mFieldList.size();j++) {
            //Field level
            addItemContent(rowCount,0,mFieldList[j].name,features_tableWidget,false);
            addItemContent(rowCount,1,QString("value ").append(j+1),features_tableWidget,false);
            item->setFlags(item->flags() & ~Qt::ItemIsEnabled);
            rowCount ++;
            //rowCount += mFieldList[j].mDefaultList.size();
            QList<DefaultItemModel> mControlItemModelList = mFieldList[j].mDefaultList;
            for (int k = 0;k<mControlItemModelList.size();k++) {
                //Default level
                addItemContent(rowCount,1,mControlItemModelList[k].name,features_tableWidget,true);
                addItemContent(rowCount,0,"",features_tableWidget,false);
                rowCount ++;
            }
        }
    }
    return rowCount;
}
