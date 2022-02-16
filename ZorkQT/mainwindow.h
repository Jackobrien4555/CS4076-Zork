#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Room.h"
#include <QMainWindow>
#include<QPushButton>
#include <iostream>
#include <string>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
     Room *a, *b, *c, *d, *e;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
   // Room* currentRoom;
     //   Room* nextRoom;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_Quit_clicked();

    void on_textEdit_copyAvailable(bool b);

    void on_northButton_clicked();

    void on_westButton_clicked();

    void on_eastButton_clicked();

    void on_southButton_clicked();

private:
    Ui::MainWindow *ui;
      QPushButton *push_button2;
      void startGame();
      void createRooms();
      void goRoom(string direction);
       vector<Room> rooms;
           Room *currentRoom;
           Room* nextRoom;
};
#endif // MAINWINDOW_H
