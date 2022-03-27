#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Room.h"
#include "item.h"
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
     Room *a, *b, *c, *d, *e,*f,*g,*h,*gameOver,*wordleRoom;


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Room* currentRoom;
        Room* nextRoom;


private slots:


    void on_Quit_clicked();

    void on_textEdit_copyAvailable(bool b);

    void on_northButton_clicked();

    void on_westButton_clicked();

    void on_eastButton_clicked();

    void on_southButton_clicked();

    void on_fight_clicked();

    void on_Search_clicked();

    void on_Unlock_clicked();

    void on_SolveWordle_clicked();

private:
           Ui::MainWindow *ui;
           QPushButton *push_button2;
           void startGame();
           void createRooms();
           void goRoom(string direction);
           void createItems();
           void displayItems();
           vector<Room> rooms;
           //Room *currentRoom;
          // Room* nextRoom;

};
#endif // MAINWINDOW_H
