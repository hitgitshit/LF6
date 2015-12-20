#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db_connect();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbLogin_clicked()
{
    login_script();
}

void MainWindow::on_lePass_returnPressed()
{
   login_script();
}

void MainWindow::on_leChat_returnPressed()
{
    send_message();
}

void MainWindow::on_pbSend_clicked()
{
    send_message();
}

//Funktionen

void MainWindow::db_connect()
{
    ui->tbLog->append("Connecting to database...");
    auth_db = QSqlDatabase::addDatabase("QSQLITE");
    auth_db.setDatabaseName("C://Users/Gregor/Desktop/lf6_chat.sqlite");
    bool ret_val = auth_db.open();

    if(ret_val == true)
    {
        ui->tbLog->append("Successful!");
        ui->tbLog->append("---------------------------");
        ui->tbLog->append("Please insert user & password");
    }
    else
    {
        ui->tbLog->append("Failed!");
        ui->tbLog->append("---------------------------");
        ui->tbLog->append("Exiting...");
        MainWindow::~MainWindow();
    }
}

void MainWindow::login_script()
{
    QSqlQuery query;
    QString ui_user = ui->leUser->text();
    QString statement = "SELECT password FROM auth WHERE user = '"+ui_user+"'";

    if( !query.exec(statement))
    {
        ui->tbLog->append("ERROR: SQL query failed.");
    }

    else
    {
        ui->tbLog->append("---------------------------");
    }

    while (query.next())
    {
        QString db_pass= query.value(0).toString();

        if(db_pass == ui->lePass->text())
        {
            ui->tbLog->append("Logged in!");
            //ui->wiLogin->isEnabled(0);
            ui->wiLogin->hide();
        }
        else
        {
            ui->tbLog->append("Connection refused: check user & password");
        }

    }

}

void MainWindow::send_message()
{
    QString time = QTime::currentTime().toString();
    QString message;
    message = time+" : "+ui->leChat->text();
    ui->tbChat->append(message);
    ui->leChat->clear();
}
