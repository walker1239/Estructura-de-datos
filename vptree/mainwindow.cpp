#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
        pixmap=new QPixmap(1041,611);
        pixmap->fill();


        QColor color("black");
        lapiz=new QPen(color);
        lapiz->setWidth(3);

        ui->base->setPixmap(*pixmap);
        q=new QPainter(pixmap);
        q->setPen(*lapiz);
          int x,y;
          srand (time(NULL));
          for(int i=0;i<100000;i++){
            x = rand() % 1041 + 0;
            y = 611-(rand() % 611 + 0);
            p.insert(x,y,30);
            //cout<<"x"<<x<<"y"<<y<<i;
          }
        p.make_vptree(q);
        //pixmap->fill();
        lapiz->setColor("orange");
        lapiz->setWidth(6);
        q->setPen(*lapiz);
        q->drawEllipse(50-1.5,611-60-1.5,3,3);
        p.search(50,611-60,5,q);
        ui->base->setPixmap(*pixmap);

}

MainWindow::~MainWindow()
{
    delete ui;
}
