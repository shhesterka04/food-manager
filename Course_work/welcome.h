#ifndef WELCOME_H
#define WELCOME_H

#include <QWidget>
#include <QMainWindow>
#include <QTableView>
#include <QTableWidget>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QtSql/QtSql>
#include <QSqlTableModel>
#include <QDate>
#include <QSqlError>
#include <QString>
#include <cstdlib>

namespace Ui {
class Welcome;
}

class Welcome : public QWidget
{
    Q_OBJECT

public:
    explicit Welcome(QWidget *parent = nullptr);
    ~Welcome();
    QString getLogin();
    QString getPass();
    bool connectDB();



signals:
    void restart();


private slots:
    void on_reg_in_clicked();
    void on_log_in_clicked();
    void on_enter_login_textEdited(const QString &arg1);
    void on_enter_password_textEdited(const QString &arg1);

    void authorizeUser();

private:
    Ui::Welcome *ui;
    QString m_username;
    QString m_userpass;

    bool m_loginSuccesfull;
    QSqlDatabase db;
    QString db_input;
};

#endif // WELCOME_H
