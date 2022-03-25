#ifndef ZORKUL_H_
#define ZORKUL_H_
#include "WordleEngine.h"
#include "mainwindow.h"
#include "wordle.h"
#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include <iostream>
#include <string>
using namespace std;

class ZorkUL {
private:
    Parser parser;
   //static Room *currentRoom;
   //static vector<Room> rooms;
  void createRooms();

    void printWelcome();
    bool processCommand(Command command);
    void printHelp();
    void goRoom(Command command);
    void createItems();
    void displayItems();
  void teleport(string direction);

public:
    ZorkUL();
    void play();
    string go(string direction);
    static string processCommand(Command command, MainWindow *MainWindow);
    // static vector<Room*> createRooms();
};

#endif /*ZORKUL_H_*/
