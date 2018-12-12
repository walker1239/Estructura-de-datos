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
        ui->base->setPixmap(*pixmap);
        //ui->make->hide();
        ui->make->setEnabled(0);
        ui->clean->setEnabled(0);
        ui->corx_search->setEnabled(0);
        ui->cory_search->setEnabled(0);
        ui->knodes->setEnabled(0);
        ui->pushButton_3->setEnabled(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_corx_editingFinished()
{
    QString x=ui->corx->text();
    cx=x.toInt();
}

void MainWindow::on_cory_editingFinished()
{
    QString x=ui->cory->text();
    cy=x.toInt();
}

void MainWindow::on_dato_2_editingFinished()
{
    QString x=ui->cory->text();
    datx=x.toInt();
}

void MainWindow::on_pushButton_pressed()
{
    p.insert(cx,611-cy,datx);
    p.print_points(q);
    ui->base->setPixmap(*pixmap);
    ui->make->setEnabled(1);
}

void MainWindow::on_ninsert_editingFinished()
{
    QString nr=ui->ninsert->text();
    n=nr.toInt();

}

void MainWindow::on_pushButton_2_pressed()
{
    int x,y;
    srand (time(NULL));
    for(int i=0;i<n;i++){
      x = rand() % 1041 + 0;
      y = 611-(rand() % 611 + 0);
      p.insert(x,y,30);
    }
    p.print_points(q);
    ui->base->setPixmap(*pixmap);
    ui->make->show();
    ui->make->setEnabled(1);

}

void MainWindow::on_make_pressed()
{
    p.make_vptree(q);
    q->setPen(*lapiz);
    ui->base->setPixmap(*pixmap);
    ui->corx_search->setEnabled(1);
    ui->cory_search->setEnabled(1);
    ui->clean->setEnabled(1);
    ui->knodes->setEnabled(1);
    ui->pushButton_3->setEnabled(1);
}

void MainWindow::on_corx_search_editingFinished()
{
    QString nr=ui->corx_search->text();
    cxs=nr.toInt();
}

void MainWindow::on_cory_search_editingFinished()
{
    QString nr=ui->cory_search->text();
    cys=nr.toInt();
}

void MainWindow::on_knodes_editingFinished()
{
    QString nr=ui->knodes->text();
    k=nr.toInt();
}

void MainWindow::on_pushButton_3_clicked()
{

    lapiz->setColor("red");
    q->setPen(*lapiz);
    //ui->base->setPixmap(*pixmap);
    p.search(cxs,611-cys,k,q);
    lapiz->setColor("green");
    q->setPen(*lapiz);
    q->drawEllipse(cxs-2,611-cys-2,4,4);
    lapiz->setColor("black");
    q->setPen(*lapiz);
    ui->base->setPixmap(*pixmap);

}

void MainWindow::on_clean_pressed()
{
    pixmap->fill();
    p.clear();
    ui->make->setEnabled(0);
    ui->clean->setEnabled(0);
    ui->corx_search->setEnabled(0);
    ui->cory_search->setEnabled(0);
    ui->knodes->setEnabled(0);
    ui->pushButton_3->setEnabled(0);
    ui->base->setPixmap(*pixmap);

}
