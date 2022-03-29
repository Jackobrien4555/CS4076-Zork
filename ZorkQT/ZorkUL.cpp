#include <iostream>
//#include "Room.h"
#include "mainwindow.h"
#include "wordle.h"
#include "item.h"
#include <cstdlib>
#include <QApplication>
#include <QTextStream>
#include <QDebug>
using namespace std;
#include "ZorkUL.h"

Parser *ZorkUL::parser;

int main(int argc, char *argv[]) {

        QApplication a(argc, argv);
        MainWindow w;

        Parser* parser = new Parser();
        WordleCode *worldleEngine = new WordleCode();
        ZorkUL::setParser(parser);
        w.show();


        delete worldleEngine;
       delete ZorkUL::getParser();
        return a.exec();


    }


/** COMMANDS **/
string ZorkUL::processCommand(Command command, Wordle *window) {
    string output = "";
    // If we're in a Wordle game, treat the input as a Wordle attempt
    if(WordleCode::getWordleStatus() == WordleCode::WORDLE_PROGRESS){
        output += WordleCode::evaluateInput(command.getCommandWord());

        if(WordleCode::getWordleStatus() == WordleCode::WORDLE_PROGRESS){
            return output;
        }
        // If it's a success, give the reward of that particular room
        else if(WordleCode::getWordleStatus() == WordleCode::WORDLE_SUCCESS){
            output += " After a minute a knife is dispensed from the machine,you pick it up wearily and continue on your way. Press exit to continue. ";

        }
    }
    //string commandWord = command.getCommandWord();
    return output;
}




void ZorkUL::setParser(Parser *parser){
   ZorkUL::parser = parser;
}

Parser* ZorkUL::getParser(){
    return ZorkUL::parser;
}



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

