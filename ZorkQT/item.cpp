#include "item.h"

Item::Item()
{

}

Item::Item(string description)
{
    this->description = description;
}

/*
 * returns the short description of the item.
 * i.e. the name of the item
 */
string Item::getShortDescription()
{
    return description;
}

string Item::getLongDescription()
{
    return " item(s), " + description + ".\n";
}
