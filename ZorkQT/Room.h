#ifndef ROOM_H_
#define ROOM_H_
#include <map>
#include <string>
#include <vector>
using namespace std;
using std::vector;


class Room {

private:
    string description;
    map<string, Room*> exit;
    string exitString();




public:

    Room(string description); //constructor
    void setExits(Room *north, Room *east, Room *south, Room *west);
    string shortDescription(); //name of the room
    string longDescription(); //objective
    Room* nextRoom(string direction);


};

#endif
