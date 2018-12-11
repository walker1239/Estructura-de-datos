#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
        pixmap=new QPixmap(1041,611);
        pixmap->fill();


        QColor color("red");
        lapiz=new QPen(color);


        ui->base->setPixmap(*pixmap);
        q=new QPainter(pixmap);
        q->setPen(*lapiz);
          int x,y;
          srand (time(NULL));
          for(int i=0;i<5;i++){
            x = rand() % 1041 + 0;
            y = 611-(rand() % 611 + 0);
            p.insert(x,y,30);
            //cout<<"x"<<x<<"y"<<y<<i;
          }
        p.make_vptree(q);
        ui->base->setPixmap(*pixmap);

}

MainWindow::~MainWindow()
{
    delete ui;
}
