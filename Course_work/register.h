#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <QString>
#include <QtSql/QtSql>
#include <QDebug>
#include <QSqlQuery>
#include <QButtonGroup>
#include <QRadioButton>
#include <QGroupBox>

#include <mainwindow.h>

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);


    ~Register();
    QString getLogin();
    QString getPass();

    QString getWeight();
    QString getHeight();
    QString getConfirm();
    QString getBirth();
    bool checkPass();

    void newUser();
    int get_cal(double height, double weight, int age, QString sex);
    double get_multi(QString goal, QString activity);
    void get_bmr(int& proteins, int& fats, int& carbohydrates, double weight, int& your_cal);


private slots:
    void on_pushButton_clicked();

    void on_login_edit_textEdited(const QString &arg1);
    void on_password_edit_textEdited(const QString &arg1);
    void on_retry_password_edit_textEdited(const QString &arg1);
    void on_weight_edit_valueChanged(double arg1);
    void on_height_edit_valueChanged(int arg1);
    void on_birth_edit_valueChanged(int arg1);

private:
    Ui::Register *ui;
    QString m_userLogin;
    QString m_userPass;
    QString m_confirmation;

    QString m_weight;
    QString m_height;
    QString m_birth;
    QString m_sex;
    QString m_goal;
    QString m_activity;
    int m_cal = 0;
    int m_proteins = 0;
    int m_fats = 0;
    int m_carbohydrates = 0;

    QSqlDatabase db;
    QString db_input;

    bool RecordUserData();

};

#endif // REGISTER_H
