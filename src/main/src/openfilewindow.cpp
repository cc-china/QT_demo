#include<QString>
#include<QFileDialog>
#include<QMessageBox>
#include<QTextStream>
#include<QMainWindow>
#include "qmenubar.h"
#include "qcoreevent.h"
#include "openfilewindow.h"
#include "qdebug.h"

static QWidget *pParent;

OpenFileWindow::OpenFileWindow(QWidget *parent,QMenuBar *qMenuBar)
    : QMainWindow(parent){
    pParent = parent;
    QList<QMenu *> menus = qMenuBar->findChildren<QMenu *>();
//    connect(menus[0], SIGNAL(triggered()),&o, SLOT(indexChild()));
    foreach (QMenu *menu, menus) {
        qDebug() << "foreach" << menu->objectName() << menu->title();
        menu->installEventFilter(this);
    }
}
OpenFileWindow::~OpenFileWindow(){}

void OpenFileWindow::openFile(){
    QString path = QFileDialog::getOpenFileName(pParent,
                   "Open File", ".", "Text Files(*.json)");
        if(!path.isEmpty()){
            QFile file(path);
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
//                QMessageBox::warning(this, "Read File",
//                             tr("Cannot open file:\n%1").arg(path));
                return;
            }
            QTextStream in(&file);
//            textEdit->setText(in.readAll());
            file.close();
        }else{
            QMessageBox::warning(pParent, "Path",
                                 "You did not select any file.");
         }
}

bool OpenFileWindow::eventFilter(QObject *obj, QEvent *event){
    if (event->type() == QEvent::MouseButtonDblClick) {
        QMenu *lab = (QMenu *)obj;
        qDebug() << "click" << lab->objectName() << lab->title();
        openFile();
    }
    return QWidget::eventFilter(obj, event);
}
