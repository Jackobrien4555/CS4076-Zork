#include <iostream>
#include "Room.h"
#include "mainwindow.h"
#include "wordle.h"
#include <cstdlib>
#include "ZorkUL.h"
#include <QApplication>
#include "wordle.h"
#include <QTextStream>
#include <QDebug>
using namespace std;
#include "ZorkUL.h"



int main(int argc, char *argv[]) {

        QApplication a(argc, argv);
        MainWindow w;

        w.show();

        return a.exec();


    }




   // else if (commandWord.compare("teleport") == 0)
  //  {
   //     Room room = randomRoom();
   //           currentRoom = &room;
    //          cout << currentRoom->longDescription() << endl;
     //     }




/** COMMANDS **/


/*void ZorkUL::teleport(string room){
    if (room.compare("rand")==0){
        unsigned int roomSize = rooms.size();
        unsigned int randRoom = rand() % roomSize;
        currentRoom = rooms[randRoom];
    }
    else{
           for (unsigned int i = 0; i < rooms.size(); i++)
           {
               if (rooms[i]->shortDescription().compare(room) == 0)
                   currentRoom = rooms[i];
           }
}
}*/
//Room ZorkUL::randomRoom() {
 //   int choice = rand() % 10;
//    return rooms[choice];
//}

