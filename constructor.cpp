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
    qDebug() << user_id;
    QSqlQuery query;
    QSqlRecord rec;
    if(!query.exec(db_input))
        {
            qDebug() << "Unable to execute query - exiting" << query.lastError() << " : " << query.lastQuery();
        }
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
    int c_cal = query.value(rec.indexOf("cal")).toInt();
    int c_proteins = query.value(rec.indexOf("proteins")).toInt();
    int c_fats = query.value(rec.indexOf("fats")).toInt();
    int c_carbohydrates = query.value(rec.indexOf("carbohydrates")).toInt();
    qDebug() << c_userLogin;
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


void Constructor::on_offer_recipe_button_clicked()
{
    Recipe winreg;
    winreg.setModal(true);
    winreg.setWindowTitle("Новый рецепт");
    winreg.exec();
}


void Constructor::on_filter_button_clicked()
{
    QSqlTableModel *model;
    model = new QSqlTableModel();
    model->setTable("Recipes");
    model->select();
    ui->recipes_list->setModel(model);

}


void Constructor::on_gen_ratio_button_clicked()
{
    qDebug() << "kekek";
    QSqlTableModel *model2;
    model2 = new QSqlTableModel();
    model2->setTable("Recipes");
    model2->select();
    ui->tableView->setModel(model2);
}

