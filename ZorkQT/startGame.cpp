#include "startGame.h"

startGame::startGame()
{
 createRooms();
}
void startGame::createRooms(){

Rooms *a, *b, *c, *d, *e;

a = new Rooms("a");
b = new Rooms("b");
c = new Rooms("c");
d = new Rooms("d");
e = new Rooms("e");


//             (N, E, S, W)
a->setExits(f, b, d, c);
b->setExits(NULL, NULL, NULL, a);
c->setExits(NULL, a, NULL, NULL);
d->setExits(a, e, k, i);
e->setExits(NULL, NULL, NULL, d);

rooms.push_back(a);
rooms.push_back(b);
rooms.push_back(c);
rooms.push_back(d);
rooms.push_back(e);


currentRoom = a;
}
