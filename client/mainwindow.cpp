
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    socket = new QTcpSocket();
    socket->connectToHost("127.0.0.1", 33333);
    connect(socket, SIGNAL(connected()), SLOT(slot_connected()));
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_SendMwssage_clicked()
{
    QString query =ui->lineEdit->text();
    SingletonClient::getInstance()->slot_send_to_server(query);
    QString str = SingletonClient::getInstance()->slot_ready_read();
    qDebug()<<"Я вывожу строку:"<< str;
    ui->lineEdit->setText(str);
}

