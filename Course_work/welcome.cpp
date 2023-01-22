#include "welcome.h"
#include "register.h"
#include "ui_welcome.h"
#include "constructor.h"
#include <QMessageBox>

Welcome::Welcome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Welcome)
{
    ui->setupUi(this);
}

Welcome::~Welcome()
{
    delete ui;
}

void Welcome::on_reg_in_clicked()
{
    Register window;
    window.setModal(true);
    window.setWindowTitle("Регистрация");
    window.exec();
}





void Welcome::on_log_in_clicked()
{
    authorizeUser();
}


void Welcome::on_enter_login_textEdited(const QString &arg1)
{
    Welcome::m_username = arg1;
}


void Welcome::on_enter_password_textEdited(const QString &arg1)
{
    Welcome::m_userpass = arg1;
}

QString Welcome::getLogin() {
    return Welcome::m_username;
}
QString Welcome::getPass() {
    return Welcome::m_userpass;
}

bool Welcome::connectDB() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./course_db.db");
    if (!db.open()) {
        qDebug() << "Cannot open database: " << db.lastError();
        return false;
    }
    return true;
}

void Welcome::authorizeUser() {
    m_username = this->getLogin();
    m_userpass = this->getPass();
    QString str_t = " SELECT * "
                    " FROM users "
                    " WHERE login = '%1'";

    QString username = "";
    QString userpass = "";

    db_input = str_t.arg(m_username);

    QSqlQuery query;
    QSqlRecord rec;

    if(!query.exec(db_input))
        {
            qDebug() << "Unable to execute query - exiting" << query.lastError() << " : " << query.lastQuery();
        }
    rec = query.record();
    query.next();
    username = query.value(rec.indexOf("login")).toString();
    userpass = query.value(rec.indexOf("password")).toString();
            if(m_username != username || m_userpass != userpass || userpass == "")
            {
                QMessageBox::information(this, "Ошибка", "Неверный пароль или пользователь отсутствует");
                m_loginSuccesfull = false;
            }
            else
            {
                m_loginSuccesfull = true;
                Constructor::user_id = query.value(rec.indexOf("user_id")).toInt();
                emit restart();

            }
};
