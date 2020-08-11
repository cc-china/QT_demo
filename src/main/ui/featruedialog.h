#ifndef FEATRUEDIALOG_H
#define FEATRUEDIALOG_H

#include <QWidget>
#include <QTableWidget>
#include <QListWidgetItem>
#include "src/featureitemmodel.h"

namespace Ui {
class FeatrueDialog;
}

class FeatrueDialog : public QWidget
{
    Q_OBJECT

public:
    explicit FeatrueDialog(QWidget *parent = nullptr);
    ~FeatrueDialog();
    void addItemContent(int row, int column, QString content,QTableWidget *features_tableWidget,bool enableChange);
    void setData(QListWidgetItem *item);
    void initView(FeatureItemModel *pFeatureItemModel= nullptr);
    qint32 getDataSetTableWeight(FeatureItemModel *pFeatureItemModel= nullptr);
private:
    Ui::FeatrueDialog *ui;
};

#endif // FEATRUEDIALOG_H
