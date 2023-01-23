/*!
\file
\brief Заголовочный файл с описанием класса Constructor
Данный файл содержит в себе определение класса Constructor
*/

#ifndef CONSTRUCTOR_H
#define CONSTRUCTOR_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlTableModel>


namespace Ui {

class Constructor;
}
/*!
\brief Класс для работы с основными функциональными элементами приложения:
 генератором меню и списком рецептов
*/
class Constructor : public QWidget
{
    Q_OBJECT

public:
    explicit Constructor(QWidget *parent = nullptr);
    ~Constructor();
    bool connectDB();
    inline  static int user_id = 0;
    void gen_table();

private slots:
    void on_Update_info_clicked();

    void on_Log_out_clicked();

    void on_filter_button_clicked();

    /*!
	\brief Метод дл генерирования рациона на 3 дня при нажатии кнопки
	*/
    void on_gen_ratio_button_clicked();

    /*!
	\brief Метод для вывода рецепта из рациона на экран
	\param &index индекс элемента таблицы
	*/
    void on_tableView_clicked(const QModelIndex &index);

    /*!
	\brief Метод для вывода рецепта из базы данных на экран
	\param &index индекс элемента списка
	*/
    void on_recipes_list_doubleClicked(const QModelIndex &index);

signals:
    void on_exit();

private:
    QString c_userLogin;
    QString c_weight;
    QString c_height;
    QString c_birth;
    QString c_sex;
    QString c_goal;
    QString c_activity;
    QString c_right;
    int c_cal = 0;
    int c_proteins = 0;
    int c_fats = 0;
    int c_carbohydrates = 0;
    Ui::Constructor *ui;
    QWidget *parent;
    QSqlDatabase db;
    QString db_input;
    QSqlQueryModel* rec_model;

};

#endif // CONSTRUCTOR_H
