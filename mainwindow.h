#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pbLogin_clicked();
    void on_lePass_returnPressed();
    void on_leChat_returnPressed();

    void send_message();
    void login_script();
    void db_connect();


    void on_pbSend_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase auth_db;

};

#endif // MAINWINDOW_H
