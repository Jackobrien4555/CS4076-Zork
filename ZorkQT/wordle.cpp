#include <iostream>
#include <fstream>
#include <string>
#include "ZorkUL.h"
#include "wordle.h"
#include "wordleCode.h"
#include "ui_wordle.h"
#include <QTextStream>
#include <QFile>
#include <QDebug>
#include <QMovie>
#include <QKeyEvent>
#include <QScrollBar>


Wordle::Wordle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Wordle)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/images/logo.png"));
     ui->outputConsole->setWordWrap(true);
     WordleCode::initialiseWordle();
     WordleCode::startWordleGame();
}

Wordle::~Wordle()
{
    delete ui;
}


void Wordle::clearConsole(){
    ui->outputConsole->clear();
}

void Wordle ::addStringToConsole(string input){

    ui->outputConsole->setText(ui->outputConsole->text() + QString::fromStdString("\n") + QString::fromStdString(input));

}

void Wordle::addQStringToConsole(QString input){

    ui->outputConsole->setText(ui->outputConsole->text() + QString::fromStdString("\n") + input);

}

void Wordle::overwriteConsole(string input){
    ui->outputConsole->clear();
    addStringToConsole(input);


}


void Wordle::parseInput(string input){
    Command *command = ZorkUL::getParser()->convertToCommand(input);
    // addStringToConsole(" " + your input + "\n");
    overwriteConsole(" " + input + "\n");
    string output = ZorkUL::processCommand(*command, this);
    //  error management
    if(output.compare("") == 0){
        // print out error
        overwriteConsole("Error ");
        return;
    }
    overwriteConsole(output);

       delete command;

       ui->input->setFocus();

   }
/**
 * is the wordle game has been completed succesfully window can be closed and the game can be continued
 * otherwise pressing quite button will terminate the program as you have failed the game by giving up or dying
 */
void Wordle::on_Quit_clicked()
{    
   if (WordleCode::getStatus() == WordleCode::WORDLE_SUCCESS){
    Wordle::close();
   } else{
     exit(0);

   }
}


void Wordle::on_input_textChanged()
{
    // Converting from QString to string
    // finding what "enter" or "\n" index is
       string input = ui->input->toPlainText().toStdString();
       size_t newlineIndex = input.find('\n');

       // not allowing you to enter more than one line
       if(newlineIndex == 0){
           ui->input->clear();
           return;
       }

       // Removing the line thats new from the string
       input = input.substr(0, newlineIndex);

       // Checks if there are any newlines or if the "enter" key is pressed
       if(newlineIndex != string::npos && input.size() > 0){
           //addStringToConsole(" " + your input + "\n");
           this->parseInput(input);

           ui->input->clear();
       }      
   }


