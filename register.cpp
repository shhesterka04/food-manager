
#include "register.h"
#include "ui_register.h"

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);

}

Register::~Register()
{
    delete ui;
}



QString Register::getPass() {
    return Register::m_userPass;
}

QString Register::getConfirm() {
    return Register::m_confirmation;
}

QString Register::getWeight() {
    return Register::m_weight;
}

QString Register::getHeight() {
    return Register::m_height;
}

QString Register::getBirth() {
    return Register::m_birth;
}

QString Register::getLogin() {
    return Register::m_userLogin;
}
void Register::on_pushButton_clicked()
{

    this->newUser();
}


void Register::on_login_edit_textEdited(const QString &arg1)
{
    Register::m_userLogin = arg1;
}


void Register::on_password_edit_textEdited(const QString &arg1)
{
    Register::m_userPass = arg1;
}


void Register::on_retry_password_edit_textEdited(const QString &arg1)
{
    Register::m_confirmation = arg1;
}


void Register::on_weight_edit_valueChanged(double arg1)
{
    Register::m_weight = QString::number(arg1);
}


void Register::on_height_edit_valueChanged(int arg1)
{
    Register::m_height = QString::number(arg1);;
}

void Register::on_birth_edit_valueChanged(int arg1)
{
    Register::m_birth = QString::number(arg1);;
}

bool Register::RecordUserData()
{
    for(auto& i: this->findChildren<QRadioButton*>())
    {
        qDebug() << i->isChecked() << ' ' << i->text();
    }
    return true;
}

void Register::newUser() {
    if(checkPass()){
        QSqlQuery query;
        int counter = 0;
        for(auto& i: this->findChildren<QRadioButton*>())
        {

            if(i->isChecked()){
                if (counter == 0){
                    m_sex = i->text();
                }
                if (counter == 1){
                    m_goal = i->text();
                }
                if (counter == 2){
                    m_activity = i->text();
                }
                counter++;
            }
        }
        m_userLogin = this->getLogin();
        m_userPass = this->getPass();

        m_weight = this->getWeight();
        m_height = this->getHeight();
        m_birth = this->getBirth();

        m_cal = this->get_cal(m_height.toDouble(), m_weight.toDouble(), m_birth.toInt(), m_sex) * this->get_multi(m_goal, m_activity);
        this->get_bmr(m_proteins, m_fats, m_carbohydrates, m_weight.toDouble(), m_cal);

        QString str_t = "INSERT INTO users(login, password, right, weight, height, birth, sex, goal, activity, cal, proteins, fats, carbohydrates)"
                        "VALUES('%1', '%2', 'пользователь', %3, %4, %5, '%6', '%7', '%8', %9, %10, %11, %12);";
        db_input = str_t .arg(m_userLogin)
                         .arg(m_userPass)
                         .arg(m_weight)
                         .arg(m_height)
                         .arg(m_birth)
                         .arg(m_sex)
                         .arg(m_goal)
                         .arg(m_activity)
                         .arg(m_cal)
                         .arg(m_proteins)
                         .arg(m_fats)
                         .arg(m_carbohydrates);
        if(!query.exec(db_input))
        {
            qDebug() << "Unable to insert data"  << query.lastError() << " : " << query.lastQuery();
        }
        else
        {
           this->hide();
        }
        }
    else {
        qDebug() << "Not OK!";
    }

}

bool Register::checkPass()
{

    return (m_confirmation == m_userPass);
}

int Register::get_cal(double height, double weight, int age, QString sex) {
    double msj_eq = 0;
    double rhb_eq = 0;
    if (sex == "Мужской") {
        msj_eq = 10 * weight + 6.25 * height - 5 * age + 5;
        rhb_eq = 13.397 * weight + 4.799 * height - 5.677 * age + 88.362;
    }
    if (sex == "Женский") {
        msj_eq = 10 * weight + 6.25 * height - 5 * age - 161;
        rhb_eq = 9.247 * weight + 3.098 * height - 4.330 * age + 447.593;
    }
    double cal_passive = (msj_eq + rhb_eq) / 2;
    return cal_passive;
}

double Register::get_multi(QString goal, QString activity) {
    double multi = 1;
    if (activity == "Очень низкая"){
        multi *= 1.2;
    }
    else if (activity == "Низкая") {
        multi *= 1.375;
    }
    else if (activity == "Средняя") {
        multi *= 1.550;
    }
    else if (activity == "Высокая") {
        multi *= 1.725;
    }
    else if (activity == "Очень высокая") {
        multi *= 1.9;
    }

    if (goal == "Набрать") {
        multi *= 1.15;
    }
    else if (goal == "Похудеть") {
        multi *= 0.85;
    }
    return multi;
}


void Register::get_bmr(int& proteins, int& fats, int& carbohydrates, double weight, int& your_cal) {
    proteins = weight * 1.6;
    fats = your_cal / 27;
    carbohydrates = (your_cal - (proteins * 4 + fats * 9)) / 4;
}





