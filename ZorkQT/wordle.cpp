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
     ui->outputConsole->setWordWrap(true);
     WordleCode::initialiseWordleEngine();
     WordleCode::startWordleGame();
}

Wordle::~Wordle()
{
    delete ui;
}

void Wordle::scrollToBottom(){
    //ui->scrollArea->verticalScrollBar()->setValue(ui->scrollArea->verticalScrollBar()->maximum());
}
void Wordle::clearConsole(){
    ui->outputConsole->clear();
}

void Wordle ::addStringToConsole(string input){
    //qDebug("Hello");
    ui->outputConsole->setText(ui->outputConsole->text() + QString::fromStdString("\n") + QString::fromStdString(input));
    scrollToBottom();
}

void Wordle::addQStringToConsole(QString input){
    //qDebug("Hello");
    ui->outputConsole->setText(ui->outputConsole->text() + QString::fromStdString("\n") + input);
    scrollToBottom();
}

void Wordle::overwriteConsole(string input){
    ui->outputConsole->clear();
    addStringToConsole(input);

    scrollToBottom();
}


void Wordle::parseInput(string input){
    Command *command = ZorkUL::getParser()->convertToCommand(input);
    //    addStringToConsole("> " + input + "\n");
    overwriteConsole("> " + input + "\n");
    string output = ZorkUL::processCommand(*command, this);

    // Processes errors
    if(output.compare("") == 0){
        //addStringToConsole(Dialogues::inputError);
        overwriteConsole("Error ");
        return;
    }
    overwriteConsole(output);


       delete command;

       ui->input->setFocus();
       scrollToBottom();
   }

void Wordle::on_Quit_clicked()
{    
   if (WordleCode::getWordleStatus() == WordleCode::WORDLE_SUCCESS){
    Wordle::close();
   } else{
     exit(0);

   }
}


void Wordle::on_input_textChanged()
{
    // Converting from QString to string and finding the index of "enter" or "\n"
       string input = ui->input->toPlainText().toStdString();
       size_t newlineIndex = input.find('\n');

       // Preventing users from entering several enter lines
       if(newlineIndex == 0){
           ui->input->clear();
           return;
       }

       // Removing the newline from the string
       input = input.substr(0, newlineIndex);

       // Checks if there are any newlines or if the "enter" key is pressed
       if(newlineIndex != string::npos && input.size() > 0){
           //addStringToConsole("> " + input + "\n");
           this->parseInput(input);

           ui->input->clear();
       }

       scrollToBottom();
   }


