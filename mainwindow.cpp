#include "./ui_mainwindow.h"
#include "mainwindow.h"
#include "register.h"
#include "constructor.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    if(!connectDB())
        {
            qDebug() << "Failed to connect DB";
        }

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_reg_in_clicked()
{
    Register window;
    window.setModal(true);
    window.setWindowTitle("Регистрация");
    window.exec();
}


void MainWindow::on_log_in_clicked()
{
    authorizeUser();
}

void MainWindow::on_exit_in_clicked()
{
    this->setCentralWidget(exit);
}


void MainWindow::on_enter_login_textEdited(const QString &arg1)
{
    MainWindow::m_username = arg1;
}


void MainWindow::on_enter_password_textEdited(const QString &arg1)
{
    MainWindow::m_userpass = arg1;
}

QString MainWindow::getLogin() {
    return MainWindow::m_username;
}
QString MainWindow::getPass() {
    return MainWindow::m_userpass;
}

bool MainWindow::connectDB() {
    // Create a QSqlDatabase object and set the driver to "QSQLITE"
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    // Set the database name and location
    db.setDatabaseName("./course_db.db");

    // Open the connection to the database
    if (!db.open()) {
        qDebug() << "Cannot open database: " << db.lastError();
        return false;
    }
    qDebug() << "Connected to the database successfully : " << db.databaseName();
    return true;
}

void MainWindow::authorizeUser() {
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
            if((m_username != username || m_userpass != userpass) || m_username == "")
            {
                qDebug() << "Try again";
                m_loginSuccesfull = false;
            }
            else
            {
                Constructor::user_id = query.value(rec.indexOf("user_id")).toInt();
                m_loginSuccesfull = true;
                menu = new Constructor;
                exit = new Welcome;

                this->setCentralWidget(menu);

                connect(menu, SIGNAL(on_exit()), this, SLOT(on_exit_in_clicked()));
                connect(exit, SIGNAL(restart()), this, SLOT(on_log_in_clicked()));
            }
};

