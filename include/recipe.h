#ifndef RECIPE_H
#define RECIPE_H

#include <QDialog>

namespace Ui {
class Recipe;
}

/*!
\brief Класс окна вывода рецепта
*/
class Recipe : public QDialog
{
    Q_OBJECT

public:
    explicit Recipe(QWidget *parent = nullptr, QString name = "", QString needed = "", QString howcook = "", QString cal = "", QString protein = "", QString fats = "", QString carbohydrates = "");
    ~Recipe();

private:
    Ui::Recipe *ui;
    QString name;
    QString needed;
    QString howcook;
    QString cal;
    QString p;
    QString f;
    QString c;
};

#endif // RECIPE_H
