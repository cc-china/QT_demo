#include "mylistbuddy.h"
#include "qdebug.h"

MyListBuddy::MyListBuddy(QWidget *parent,QSize *qSize) : QWidget(parent)
{
    initUi(qSize);
}

MyListBuddy::~MyListBuddy() {}

void MyListBuddy::initUi(QSize *qSize) {
    pItemCheckBox=new QCheckBox(this);
    pFeaturesStr=new QLabel(this);
    pDetailsStr=new QLabel(this);
    pDividerLine =new QLabel(this);
    //设置复选框大小
    pItemCheckBox->setFixedSize(40,40);
    //设置详细textview字体为灰色
    QPalette color;
    color.setColor(QPalette::Text,Qt::gray);
    pDetailsStr->setPalette(color);
    //布局
    pItemCheckBox->move(0,3);
    pFeaturesStr->move(0,3);
    pDetailsStr->move(0,20);
    pDividerLine->move(0,qSize->height()-1);
    pDividerLine->setFrameStyle(QFrame::HLine | QFrame::Raised);
    //设置背景颜色
    //pDetailsStr->setStyleSheet("background:blue");
    //设置宽度、高度
    pFeaturesStr->setFixedSize(QSize(qSize->width()-40,qSize->height()/2));
    pDetailsStr->setFixedSize(QSize(qSize->width()-40,qSize->height()/2));
    pDividerLine->setFixedSize(QSize(qSize->width(),1));
    //设置Label控件的内容居中
    pFeaturesStr->setAlignment(Qt::AlignCenter);
    pDetailsStr->setAlignment(Qt::AlignCenter);
}

void MyListBuddy::setData() {}
