#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <time.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    pixmap=new QPixmap(641,400);
    pixmap->fill();
    //circulo=new QPixmap(400,300);
    //circulo->fill();

    //color.setNamedColor("black");
    color.setRgb(0,0,0,255);
    lapiz=new QPen(color);

    ui->base->setPixmap(*pixmap);
    q=new QPainter(pixmap);
    int x;
    int y;
    int r;
    srand (time(NULL));
    for(int i=0;i<100;i++){
        x=rand() % 641;
        y=400-rand() % 400;
        r=rand() % 100;
        q->drawPoint(x,y);
        q->drawEllipse(x-(r/2),y-(r/2),r,r);
    }
    ui->base->setPixmap(*pixmap);
}

MainWindow::~MainWindow()
{
    delete ui;
}
