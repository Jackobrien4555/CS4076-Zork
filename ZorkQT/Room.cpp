#include "Room.h"

Room::Room(string description) {
    this->description = description;
}

void Room::setExits(Room *north, Room *east, Room *south, Room *west) {
    if (north != NULL)
        exit["North"] = north;
    if (east != NULL)
        exit["East"] = east;
    if (south != NULL)
        exit["South"] = south;
    if (west != NULL)
        exit["West"] = west;
}

string Room::shortDescription() {
    return description;
}

string Room::longDescription() {
    return "room = " + description + ".\n"  + exitString();
}

string Room::exitString() {
    string returnString = "\nexits =";
    for (map<string, Room*>::iterator i = exit.begin(); i != exit.end(); i++)
        // Loop through map
        returnString += "  " + i->first;	// access the "first" element of the pair (direction as a string)
    return returnString;
}

Room* Room::nextRoom(string dir) {
    map<string, Room*>::iterator next = exit.find(dir); //returns an iterator for the "pair"
    if (next == exit.end())
        return NULL; // if exits.end() was returned, there's no room in that direction.
    return next->second; // If there is a room, remove the "second" (Room*)
    // part of the "pair" (<string, Room*>) and return it.
}

void Room::addItemsToRoom(Item *item1)
{
    this->roomItems = item1;
    this->hasItem = true;
}


Item* Room::getItemFromRoom()
{
    return roomItems;
}

bool Room::checkItem()
{
    return hasItem;
}

void Room::setHasItem(bool flag)
{
    this->hasItem = flag;
}