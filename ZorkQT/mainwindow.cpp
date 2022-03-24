#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "wordle.h"
//#include "Command.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Welcome to Zork 2:Electric Boogaloo");
    setFixedSize(geometry().width(),geometry().height());

  startGame();

}

void MainWindow::startGame()
{

     createRooms();
     ui->photoWidget->setCurrentIndex(0);
     ui->interactWidget->setCurrentIndex(1);
}
void MainWindow::createRooms()
{
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
    currentRoom = a;

    Item *key;
    key = new Item("Key", true);
    d->addItemsToRoom(key);

}
void MainWindow::goRoom(string direction)
{
    nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL)
    {
        ui->textEdit->setText(QString::fromStdString("Invalid Move"));
    }
    else
    {
        currentRoom = nextRoom;
        ui->textEdit->setText(QString::fromStdString("Current Room: " + currentRoom->shortDescription()));


    }

}

/*
 * Listener for when the Space button is clicked.
 * Button only works if current room is C - The Control Room
 * Displays message and ends game
 */
MainWindow::~MainWindow()
{
    delete a;
    delete b;
    delete c;
    delete d;
    delete e;
    delete f;
    delete g;
    delete h;
    delete gameOver;
    delete ui;
}


void MainWindow::on_Quit_clicked()
{
   MainWindow::close();
}


void MainWindow::on_textEdit_copyAvailable(bool b)
{

    ui->textEdit->setText("Welcome to the world of Zork,where it's always raining and wordle is king.");
}


void MainWindow::on_northButton_clicked()
{
    if (currentRoom == a) {
   ui->photoWidget->setCurrentIndex(1);
    ui->textWidget->setCurrentIndex(1);

    } if (currentRoom == b )  {

         ui->photoWidget->setCurrentIndex(2);
         ui->textWidget->setCurrentIndex(2);

     }
     if (currentRoom == c) {
        ui->photoWidget->setCurrentIndex(5);
         ui->textWidget->setCurrentIndex(5);
    } if (currentRoom == d) {
        ui->photoWidget->setCurrentIndex(4);
         ui->textWidget->setCurrentIndex(4);
    } if (currentRoom ==e) {
        ui->photoWidget->setCurrentIndex(7);
         ui->textWidget->setCurrentIndex(7);
    }
    if(currentRoom ==d){
         ui->interactWidget->setCurrentIndex(0);
    }
     goRoom("North");
}


void MainWindow::on_westButton_clicked()
{

     if (currentRoom == b ) {
         ui->photoWidget->setCurrentIndex(3);
         ui->textWidget->setCurrentIndex(3);
       if(ui->itemWidget->currentIndex()==0){

           ui->interactWidget->setCurrentIndex(2);
     }            if (currentRoom == e) {
         ui->photoWidget->setCurrentIndex(1);
         ui->textWidget->setCurrentIndex(1);
}
 goRoom("West");
}
}


void MainWindow::on_eastButton_clicked()
{

     if (currentRoom == b) {
         ui->photoWidget->setCurrentIndex(6);
         ui->textWidget->setCurrentIndex(6);
     }
           if (currentRoom == d) {
               ui->photoWidget->setCurrentIndex(1);
               ui->textWidget->setCurrentIndex(1);
}
 goRoom("East");
}


void MainWindow::on_southButton_clicked()
{
    if (currentRoom == c) {
         ui->photoWidget->setCurrentIndex(1);
         ui->textWidget->setCurrentIndex(1);
    } if (currentRoom == b) {
         ui->photoWidget->setCurrentIndex(0);
         ui->textWidget->setCurrentIndex(0);
    } if (currentRoom == g) {
         ui->photoWidget->setCurrentIndex(2);
         ui->textWidget->setCurrentIndex(2);
    } if (currentRoom == f) {
         ui->photoWidget->setCurrentIndex(3);
         ui->textWidget->setCurrentIndex(3);
         ui->interactWidget->setCurrentIndex(2);
    } if (currentRoom == h) {
         ui->photoWidget->setCurrentIndex(6);
         ui->textWidget->setCurrentIndex(6);
    }
         goRoom("South");

}



void MainWindow::on_fight_clicked()
{
     ui->photoWidget->setCurrentIndex(8);
     ui->textWidget->setCurrentIndex(8);
     goRoom("gameOver");
}


void MainWindow::on_Search_clicked()
{

    if(currentRoom->checkItem()){
            if (currentRoom->getItemFromRoom()->getItemName() == "Key"){
          ui->itemWidget->setCurrentIndex(1);
          ui->textWidget->setCurrentIndex(9);


}
           currentRoom->setHasItem(false);
           ui->interactWidget->setCurrentIndex(3);

    }
}


void MainWindow::on_Unlock_clicked()
{
   if(currentRoom==b){
       ui->photoWidget->setCurrentIndex(2);
       ui->textWidget->setCurrentIndex(2);
       ui->interactWidget->setCurrentIndex(4);
       goRoom("North");
   }

}


void MainWindow::on_SolveWordle_clicked()
{
    if(currentRoom == b){
   Wordle wordle;
   wordle.setModal(true);
   wordle.exec();
    }
}

