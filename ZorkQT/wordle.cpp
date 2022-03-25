/*#include "wordle.h"
#include "ui_wordle.h"
#include "WordleEngine.h"
#include "ZorkUL.h"
#
Wordle::Wordle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Wordle)
{
    ui->setupUi(this);
    WordleEngine::initialiseWordleEngine();
    WordleEngine::startWordleGame();
}

string ZorkUL::processCommand(Command command, Wordle *window) {
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

Wordle::~Wordle()
{
    delete ui;
}



void Wordle::on_Quit_clicked()
{
    Wordle::close();
}


void Wordle::on_Enter_clicked()
{

}
*/
