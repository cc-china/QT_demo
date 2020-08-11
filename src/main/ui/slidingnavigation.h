#ifndef SLIDINGNAVIGATION_H
#define SLIDINGNAVIGATION_H

#include <QWidget>
#include <QListWidgetItem>

namespace Ui {
class SlidingNavigation;
}

class SlidingNavigation : public QWidget
{
    Q_OBJECT

public:
    explicit SlidingNavigation(QWidget *parent = nullptr);
    ~SlidingNavigation();
private slots:
    void on_lw_features_itemClicked(QListWidgetItem *item);

private:
    Ui::SlidingNavigation *ui;
};

#endif // SLIDINGNAVIGATION_H
