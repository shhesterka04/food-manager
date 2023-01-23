#include "constructor.h"
#include "ui_constructor.h"
#include "register.h"
#include "recipe.h"

#include <QListView>
#include <QStandardItemModel>






Constructor::Constructor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Constructor)
{
    QString str_t = " SELECT * "
                    " FROM users "
                    " WHERE user_id = '%1'";
    db_input = str_t.arg(user_id);
    QSqlQuery query;
    QSqlRecord rec;
    query.exec(db_input);
    query.next();
    rec = query.record();
    c_userLogin = query.value(rec.indexOf("login")).toString();
    c_weight = query.value(rec.indexOf("weight")).toString();
    c_height = query.value(rec.indexOf("height")).toString();
    c_birth = query.value(rec.indexOf("birth")).toString();
    c_right = query.value(rec.indexOf("right")).toString();
    c_sex = query.value(rec.indexOf("sex")).toString();
    c_goal = query.value(rec.indexOf("goal")).toString();
    c_activity = query.value(rec.indexOf("activity")).toString();
    c_cal = query.value(rec.indexOf("cal")).toInt();
    c_proteins = query.value(rec.indexOf("proteins")).toInt();
    c_fats = query.value(rec.indexOf("fats")).toInt();
    c_carbohydrates = query.value(rec.indexOf("carbohydrates")).toInt();
    ui->setupUi(this);
    ui->user_login_label->setText(c_userLogin);
    ui->user_activity_label->setText(c_activity);
    ui->user_goal_label->setText(c_goal);
    ui->user_height_label->setText(c_height);
    ui->user_lweight_label->setText(c_weight);
    ui->user_right_label->setText(c_right);
    ui->user_years_label->setText(c_birth);
    ui->user_sex_label->setText(c_sex);
    ui->user_cal_label->setText(QString::number(c_cal));
    ui->user_p_label->setText(QString::number(c_proteins));
    ui->user_c_label->setText(QString::number(c_fats));
    ui->user_f_label->setText(QString::number(c_carbohydrates));

    QSqlQueryModel *model1 = new QSqlQueryModel;
    QSqlQuery query1;
    QString temp = "SELECT Name FROM Recipes";
    query1.exec(temp);
    model1->setQuery(query1);
    ui->recipes_list->setModel(model1);
}

Constructor::~Constructor()
{
    delete ui;
}


void Constructor::on_Update_info_clicked()
{
    Register window;
    window.setModal(true);
    window.setWindowTitle("Регистрация");
    window.exec();
}


void Constructor::on_Log_out_clicked()
{
    emit on_exit();

}




void Constructor::on_filter_button_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery query;
    QString temp = "SELECT Name FROM Recipes"
           " WHERE (Calories >= %1) AND (Calories <= %2) "
           " AND (Protein >= %3) AND (Protein <= %4)"
           " AND (Carbohydrate >= %5) AND (Carbohydrate <= %6)"
           " AND (Fat >= %7) AND (Fat <= %8)";;
    int cal_min = ui->min_cal->text().toInt();
    int cal_max = ui->max_cal->text().toInt();
    int p_min = ui->min_p->text().toInt();
    int p_max = ui->max_p->text().toInt();
    int f_min = ui->min_f->text().toInt();
    int f_max = ui->max_f->text().toInt();
    int c_min = ui->min_p_2->text().toInt();
    int c_max = ui->max_c->text().toInt();
    QString sql_request = temp.arg(cal_min).arg(cal_max).arg(p_min).arg(p_max).arg(f_min).arg(f_max).arg(c_min).arg(c_max);
    query.exec(sql_request);
    model->setQuery(query);
    ui->recipes_list->setModel(model);

}


void Constructor::on_gen_ratio_button_clicked()
{
    QStandardItemModel *model = new QStandardItemModel;
    ui->tableView->verticalHeader()->setMinimumSectionSize(75);
    ui->tableView->setModel(model);
    QStringList headerLabels = {"Завтрак", "Обед", "Ужин"};
    model->setVerticalHeaderLabels(headerLabels);
    ui->tableView->show();
    for (int row = 0; row < 3; row++) {
        int day_cal = this->c_cal;
        int day_p = this->c_proteins;
        int day_c = this->c_carbohydrates;
        int day_f = this->c_fats;
        for (int col = 0; col < 3; col++) {
            QString str_t = " SELECT * "
                            " FROM Recipes "
                            " WHERE Calories <= %1 AND Protein <= %2 AND Carbohydrate <= %3 AND Fat <= %4"
                            " ORDER BY Frequency, Calories DESC, Protein DESC, Fat DESC, Carbohydrate"
                            " LIMIT 1";
            db_input = str_t.arg(day_cal).arg(day_p).arg(day_c).arg(day_f);
            QSqlQuery query;
            QSqlRecord rec;
            query.exec(db_input);
            query.next();
            rec = query.record();
            day_cal -= rec.value(3).toInt();
            day_p -= rec.value(4).toInt();
            day_c -= rec.value(6).toInt();
            day_f -= rec.value(5).toInt();
            int fl = rec.value(8).toInt();
            fl++;
            QStandardItem *item = new QStandardItem(rec.value(0).toString());
            model->setItem(col, row, item);
            str_t = "UPDATE Recipes SET Frequency = '%1' WHERE Name = '%2';";
            db_input = str_t.arg(fl).arg(rec.value(0).toString());
            query.exec(db_input);
        }
    }
}



void Constructor::on_tableView_clicked(const QModelIndex &index)
{
    QString cellText = ui->tableView->model()->data(index, Qt::DisplayRole).toString();
    QString str_t = " SELECT * "
                    " FROM Recipes "
                    " WHERE Name == '%1'";
    db_input = str_t.arg(cellText);
    QSqlQuery query;
    QSqlRecord rec;
    query.exec(db_input);
    query.next();
    rec = query.record();
    ui->label_17->setText(cellText);
    QString ing = query.value(rec.indexOf("Ingredients")).toString();
    QString how = query.value(rec.indexOf("Recipe")).toString();
    ui->label_13->setText(ing);
    ui->how_cook->setText(how);
}



void Constructor::on_recipes_list_doubleClicked(const QModelIndex &index)
{
    QString cellText = ui->recipes_list->model()->data(index, Qt::DisplayRole).toString();
    QString str_t = " SELECT * "
                    " FROM Recipes "
                    " WHERE Name == '%1'";
    db_input = str_t.arg(cellText);
    QSqlQuery query;
    QSqlRecord rec;
    query.exec(db_input);
    query.next();
    rec = query.record();
    QString ing = query.value(rec.indexOf("Ingredients")).toString();
    QString how = query.value(rec.indexOf("Recipe")).toString();
    QString rec_cal = query.value(rec.indexOf("Calories")).toString();
    QString rec_p = query.value(rec.indexOf("Protein")).toString();
    QString rec_f = query.value(rec.indexOf("Fat")).toString();
    QString rec_c = query.value(rec.indexOf("Carbohydrate")).toString();
    Recipe winreg(nullptr,cellText,ing,how,rec_cal,rec_p,rec_f,rec_c);
    winreg.setModal(true);
    winreg.setWindowTitle(cellText);
    winreg.exec();
}

