#include "detailspage.h"
#include "ui_detailspage.h"
#include "ui/featureitemview.h"
#include "qdebug.h"

DetailsPage::DetailsPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DetailsPage)
{
    ui->setupUi(this);
    QScrollArea *scrollArea = ui->scrollArea;
    QWidget *scrollAreaWidgetContents = ui->scrollAreaWidgetContents;
    QGridLayout *features_gridLayout = ui->features_gridLayout;
    scrollAreaWidgetContents->setMinimumSize(QSize(350,8500));
    ui->scrollAreaWidgetContents->setLayout(features_gridLayout);
    //scrollAreaWidgetContents->setFixedHeight(5000);
    for(int i = 0;i<30;i++){
        int row = i/2;
        int column = i % 2;
        qDebug() << "row=" <<row<<"----column="<<column;
        FeatureItemView *featureItemView = new FeatureItemView(this);
        features_gridLayout->addWidget(featureItemView,row,column);
    }

}

DetailsPage::~DetailsPage()
{
    delete ui;
}
