/*!
\file
\brief Заголовочный файл с описанием класса MainWindow
Данный файл содержит в себе определение класса MainWindow
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "constructor.h"
#include "welcome.h"

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

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
/*!
\brief Класс главного рабочего окна
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool connectDB();
    QString getLogin();
    QString getPass();


private slots:
    /*!
	\brief Метод для регистрации пользователя в приложении после нажатия кнопки "Регистрация"
	*/
    void on_reg_in_clicked();

        /*!
	\brief Метод для авторизации пользователя в приложении после нажатия кнопки "Авторизация"
	*/
    void on_log_in_clicked();

    void on_exit_in_clicked();

    void on_enter_login_textEdited(const QString &arg1);

    void on_enter_password_textEdited(const QString &arg1);

        /*!
	\brief Метод для проверки корректности введенных данных и записи аккаунта в Базу данных
	*/
    void authorizeUser();

private:
    Ui::MainWindow *ui;
    Constructor* menu;
    Welcome* exit;
    QString m_username;
    QString m_userpass;

    bool m_loginSuccesfull;
    QSqlDatabase db;
    QString db_input;

};
#endif // MAINWINDOW_H
