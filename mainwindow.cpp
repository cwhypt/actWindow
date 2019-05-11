#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mp=ui->mainPage;  //注意这儿不能加QWidget！！否则重定义为局域函数
    ap=ui->autoPage;
    currentPage=ui->mainPage;
    //TableEditor *tbUpdate = mp->findChild<TableEditor *>();
    //connect(tbUpdate,SIGNAL(updateTable()),this,SLOT(update0()));
    ap->hide();

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_mainButton_clicked()
{
    currentPage->hide();
    mp->show();
    currentPage=mp;
}

void MainWindow::on_autoButton_clicked()
{
    currentPage->hide();
    ap->show();
    currentPage=ap;
}
