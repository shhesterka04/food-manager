#include "constructor.h"
#include "ui_constructor.h"
#include "register.h"




Constructor::Constructor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Constructor)
{
    ui->setupUi(this);
}

Constructor::~Constructor()
{
    delete ui;
}


void Constructor::on_Update_info_clicked()
{
    Register window;
    window.setModal(true);
    window.exec();
}


void Constructor::on_Log_out_clicked()
{
    //Log_in* li = new Log_in(this);
    //this->setCentralWidget(li);
}

