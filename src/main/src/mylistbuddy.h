#ifndef MYLISTBUDDY_H
#define MYLISTBUDDY_H

#include <QWidget>
#include <QCheckBox>
#include <QLabel>
#include <QListWidget>
class MyListBuddy : public QWidget
{
    Q_OBJECT
public:
    explicit MyListBuddy(QWidget *parent = nullptr,QSize *qSize = nullptr);
    ~MyListBuddy();

    void initUi(QSize *qSize = nullptr);
    void setData();
    QCheckBox *pItemCheckBox;
    QLabel *pFeaturesStr;
    QLabel *pDetailsStr;
    QLabel *pDividerLine;
signals:

public slots:
};

#endif // MYLISTBUDDY_H
