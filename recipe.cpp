
#include "recipe.h"
#include "ui_recipe.h"

Recipe::Recipe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Recipe)
{
    ui->setupUi(this);
}

Recipe::~Recipe()
{
    delete ui;
}
