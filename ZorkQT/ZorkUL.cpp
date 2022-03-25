#include <iostream>
#include "mainwindow.h"
#include "wordle.h"
#include <cstdlib>
#include "ZorkUL.h"
#include <QApplication>
//#include "errors.h"
#include <QTextStream>
#include <QDebug>
using namespace std;
#include "ZorkUL.h"



int main(int argc, char *argv[]) {

        QApplication a(argc, argv);
        MainWindow w;
        WordleEngine *worldleEngine = new WordleEngine();
        w.show();


        delete worldleEngine;
        return a.exec();
    }



/*void ZorkUL::createRooms()  {
    Room *a, *b, *c,*d, *e, *f, *g,*h, *gameOver;

    a = new Room("A - Dark Street/Start Point");
    b = new Room("B - Bar Entrance");
    c = new Room("C - Bar");
    d = new Room("D - Alleyway");
    e = new Room("E - 24/7 Shop");
    f = new Room("F - Danger Alley");
    g = new Room("G - End screen");
    h = new Room("H - Inside of store");
    gameOver = new Room("Game Over - You have died");

    //(N, E, S, W)
    a->setExits(b, NULL, NULL, NULL);
    b->setExits(c, e, a, d);
    c->setExits(g, NULL, b, NULL);
    d->setExits(f,b, NULL, NULL);
    e->setExits(h, NULL, NULL, b);
    f->setExits(gameOver,NULL, d, NULL);
    g->setExits(NULL, NULL, c, NULL);
    h->setExits(NULL,NULL,e,NULL);
    gameOver->setExits(NULL,NULL,NULL,NULL);

   rooms.push_back(a);
      rooms.push_back(b);
       rooms.push_back(c);
      rooms.push_back(d);
       rooms.push_back(e);
      rooms.push_back(f);
       rooms.push_back(g);
       rooms.push_back(h);
       rooms.push_back(gameOver);


    currentRoom = a;
    rooms = {*a, *b, *c, *d, *e, *f, *g, *h, *gameOver};
    Item *key;
    key = new Item("Key", true);
    d->addItemsToRoom(key);

}



 *  Main play routine.  Loops until end of play.

void ZorkUL::play() {
    printWelcome();

    // Enter the main command loop.  Here we repeatedly read commands and
    // execute them until the ZorkUL game is over.

    bool finished = false;
    while (!finished) {
        // Create pointer to command and give it a command.
        Command* command = parser.getCommand();
        // Pass dereferenced command and check for end of game.
        finished = processCommand(*command);
        // Free the memory allocated by "parser.getCommand()"
        //   with ("return new Command(...)")
        delete command;
    }
    cout << endl;
    cout << "end" << endl;
} */



/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
bool ZorkUL::processCommand(Command command) {
    if (command.isUnknown()) {
        cout << "invalid input"<< endl;

    }
    return false;
}


string ZorkUL::processCommand(Command command, MainWindow *MainWindow) {
    string output = "";
    // If we're in a Wordle game, treat the input as a Wordle attempt
    if(WordleEngine::getWordleStatus() == WordleEngine::WORDLE_PROGRESS){
        output += WordleEngine::evaluateInput(command.getCommandWord());

        if(WordleEngine::getWordleStatus() == WordleEngine::WORDLE_PROGRESS){
            return output;
        }
        // If it's a success, give the reward of that particular room
        else if(WordleEngine::getWordleStatus() == WordleEngine::WORDLE_SUCCESS){
            output = "congrats";
        }
    }
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

