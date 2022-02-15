#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Welcome to Zork 2:Electric Boogaloo");
    setFixedSize(geometry().width(),geometry().height());

}

MainWindow::~MainWindow()
{

delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->textEdit->setText("Hello World");
}


void MainWindow::on_pushButton_2_clicked()
{
ui->textEdit->setText("Welcome to Zork");
}


void MainWindow::on_Quit_clicked()
{
   MainWindow::close();
}

