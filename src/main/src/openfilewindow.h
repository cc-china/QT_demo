#ifndef OPENFILEMAINWINDOW_H
#define OPENFILEMAINWINDOW_H
#include<QMainWindow>
#include <QWidget>

class OpenFileWindow: public QMainWindow
{
public:
    OpenFileWindow(QWidget *parent = nullptr,
                   QMenuBar *qMenuBar= nullptr);
    ~OpenFileWindow();
     void openFile();

protected:
    bool eventFilter(QObject *, QEvent *);

};

#endif // OPENFILEMAINWINDOW_H
