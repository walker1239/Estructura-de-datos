#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPainter>
#include <QMainWindow>
#include "vptree.h"
#include <QTimer>
typedef int D;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_corx_editingFinished();

    void on_cory_editingFinished();

    void on_dato_2_editingFinished();

    void on_pushButton_pressed();

    void on_ninsert_editingFinished();

    void on_pushButton_2_pressed();

    void on_make_pressed();

    void on_corx_search_editingFinished();

    void on_cory_search_editingFinished();

    void on_knodes_editingFinished();

    void on_pushButton_3_clicked();

    void on_clean_pressed();

private:
    Ui::MainWindow *ui;
    QPainter *q;
    QPixmap *pixmap;
    QPen *lapiz;
    vptree<D> p;
    int cx,cxs;
    int cy,cys;
    int n;
    int k;
    D datx;
};

#endif // MAINWINDOW_H
