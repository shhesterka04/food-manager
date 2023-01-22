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
    void on_reg_in_clicked();

    void on_log_in_clicked();

    void on_exit_in_clicked();

    void on_enter_login_textEdited(const QString &arg1);

    void on_enter_password_textEdited(const QString &arg1);

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
