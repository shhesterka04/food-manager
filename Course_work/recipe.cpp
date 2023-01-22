
#include "recipe.h"
#include "ui_recipe.h"

Recipe::Recipe(QWidget *parent, QString name, QString needed, QString howcook, QString cal, QString protein, QString fats, QString carbohydrates) :
    QDialog(parent),
    ui(new Ui::Recipe),
    name(name),
    needed(needed),
    howcook(howcook),
    cal(cal),
    p(protein),
    f(fats),
    c(carbohydrates)
{

    ui->setupUi(this);
    ui->cLabel->setText(c);
    ui->calLabel->setText(cal);
    ui->fLabel->setText(f);
    ui->pLabel->setText(p);
    ui->howCookLabel->setText(howcook);
    ui->ingLabel->setText(needed);
}

Recipe::~Recipe()
{
    delete ui;
}

