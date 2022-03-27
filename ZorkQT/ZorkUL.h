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

   //static Room *currentRoom;
   //static vector<Room> rooms;
  void createRooms();

    void printWelcome();

    void printHelp();
    void goRoom(Command command);
    void createItems();
    void displayItems();
  void teleport(string direction);

public:
    ZorkUL();
    void play();
    string go(string direction);


    static bool compareIgnoreCase(string a, string b);
    static string stringToLower(string a);
};

#endif /*ZORKUL_H_*/
