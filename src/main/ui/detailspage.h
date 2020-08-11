#ifndef DETAILSPAGE_H
#define DETAILSPAGE_H

#include <QWidget>
#include <QGridLayout>
#include <QLayoutItem>

namespace Ui {
class DetailsPage;
}

class DetailsPage : public QWidget
{
    Q_OBJECT

public:
    explicit DetailsPage(QWidget *parent = nullptr);
    ~DetailsPage();

private:
    Ui::DetailsPage *ui;
};

#endif // DETAILSPAGE_H
