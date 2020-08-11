#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "openfilewindow.h"
#include "ui/slidingnavigation.h"
#include "ui/DetailsPage.h"
#include "qdebug.h"

QWidget *w_slidingnavigation;
bool arrowClickStatus = false;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMenuBar *qMenuBar = ui->menubar;
    QPushButton  *btn_arrow = ui->btn_arrow;
    QWidget  *w_detailsPage = ui->w_detailsPage;
    w_slidingnavigation = ui->w_slidingnavigation;
    w_slidingnavigation->setVisible(0);

    connect(btn_arrow, SIGNAL(clicked()),this, SLOT(setVisibles()));

    QVBoxLayout  *layout_slidingNavigation = new QVBoxLayout();
    SlidingNavigation *slidingNavigation = new SlidingNavigation(this);
    layout_slidingNavigation->addWidget(slidingNavigation);
    w_slidingnavigation->setLayout(layout_slidingNavigation);

    QVBoxLayout *layout = new QVBoxLayout();
    DetailsPage *detailsPage = new DetailsPage();
    layout->addWidget(detailsPage);
    //w_detailsPage->setLayout(layout);

    OpenFileWindow *openFileWindow = new OpenFileWindow(this,qMenuBar);
    (void) openFileWindow;
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setVisibles(){
    qDebug() << "setVisibles";
    if(!arrowClickStatus){
        arrowClickStatus = true;
        w_slidingnavigation->setVisible(1);
    }else{
        arrowClickStatus = false;
        w_slidingnavigation->setVisible(0);
    }
}
