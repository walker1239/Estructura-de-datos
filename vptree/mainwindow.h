#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPainter>
#include <QMainWindow>

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
    QPixmap *pixmap;
    QPen *lapiz;
    QPainter *q;
    QColor color;
};

#endif // MAINWINDOW_H
