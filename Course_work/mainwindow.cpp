#include "mainwindow.h"
#include "register.h"
#include "constructor.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_reg_in_clicked()
{
    Register window;
    window.setModal(true);
    window.exec();
}


void MainWindow::on_log_in_clicked()
{
    Constructor* menu = new Constructor;
    this->setCentralWidget(menu);
}

