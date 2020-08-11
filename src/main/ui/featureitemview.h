#ifndef FEATUREITEMVIEW_H
#define FEATUREITEMVIEW_H

#include <QWidget>
#include <QTableWidget>
namespace Ui {
class FeatureItemView;
}

class FeatureItemView : public QWidget
{
    Q_OBJECT

public:
    explicit FeatureItemView(QWidget *parent = nullptr);
    ~FeatureItemView();
    void addItemContent(int row, int column, QString content,QTableWidget *features_tableWidget);
private:
    Ui::FeatureItemView *ui;
};

#endif // FEATUREITEMVIEW_H
