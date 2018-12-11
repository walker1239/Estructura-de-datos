#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPainter>
#include <QMainWindow>
#include "vptree.h"
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPainter *q;
    QPixmap *pixmap;
    QPen *lapiz;
    vptree<int> p;
};

#endif // MAINWINDOW_H
