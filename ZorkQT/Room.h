#ifndef ROOM_H_
#define ROOM_H_
#include <map>
#include <string>
#include <vector>
#include "item.h"

using std::vector;
using namespace std;
using std::vector;

// Abstract class holding properties that rooms will have,ie. if it has an item
class RoomProps{
public:
      virtual bool hasItems() = 0;
};


//friend class of Mainwindow allowing it to access its private and protected members
class Room : public RoomProps {
    friend class MainWindow;

private:

     bool fileRead = false;
     Item *roomItems;

protected:
     vector <Item*> itemsInRoom;
     string description;
     map<string, Room*> exit;
     string exitString();

public:

     Room(string description=" ",bool item=false); //constructor
     Room(const Room &R1);

     virtual ~Room();
     union {
             Item* item;
             ;
    };
     bool hasItem;
     int numberOfItems();
     void addItemsToRoom(Item *item1);
     Item* getItemFromRoom();
     vector<Item*> getItems();
     bool checkItem();
     void setHasItem(bool flag);
     bool hasItems() override;

     void setExits(Room *north, Room *east, Room *south, Room *west);
     string shortDescription(); //name of the room
     string longDescription(); //objective
     Room* nextRoom(string direction);


};

class WordleRoom : public Room{
     WordleRoom(string(*interactFunc));
};

#endif
