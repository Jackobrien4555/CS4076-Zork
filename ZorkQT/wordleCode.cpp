#include "wordleCode.h"
#include <QTextStream>
#include <QFile>
#include <wordle.h>

using std::ifstream;
using std::getline;
using std::cout;
using std::endl;

vector<string> WordleCode::allPossibleWords;
int WordleCode::triesLeft;
WordleCode::Status WordleCode::wordleStatus = WordleCode::WORDLE_STOP;
string WordleCode::goalWord;


void WordleCode::inititialiseWords(string filename){
    if(filename.empty()){     
        QFile file(":/words.txt");
        QTextStream in(&file);
        if (file.open(QFile::ReadOnly | QFile::Text)){
            while(!in.atEnd()){            
                WordleCode::allPossibleWords.push_back(in.readLine().toStdString());
            }
        }
        file.close();
    }
}

void WordleCode::initialiseWordle(){
    inititialiseWords("");
    WordleCode::wordleStatus = WordleCode::WORDLE_CURRENT;
}

void WordleCode::startWordleGame(){
    //makes it random
    srand(time(NULL));
    WordleCode::triesLeft = 5;
    // Get a random word
    WordleCode::goalWord = allPossibleWords.at(rand() % allPossibleWords.size());
}

string WordleCode::checkInput(const string &input){
    string output = "";
    std::unordered_map<char, int> letter_counts; // a map of letters
    string correctWord = WordleCode::goalWord; // the word we are trying to guess
    int correctLettersAmount = 0;

    //input must be the same size as the correct word i.e 5 in this case
    if(input.size() != correctWord.size()){
        return "";
    }

    //  Pairing each letter in the letter_counts map with 1
    for(int i = 0; i < (int) correctWord.size(); i++){
        char currentChar = tolower(correctWord.at(i));
        // If the letter does not exist yet, add it and pair it with the int 1
        // Otherwise, just add 1 to that entry.
        if(letter_counts.count(currentChar)){
            letter_counts[currentChar] += 1;
        }
        else{
            letter_counts.insert({currentChar, 1});
        }
    }

    for(int i = 0; i < (int) input.size(); i++){
        char currentInputLetter = input.at(i);

        // If the character is in the right spot place a [] around it indicating its correct
        if(WordleCode::isEqualIgnoreCase(currentInputLetter, correctWord.at(i))){
            letter_counts[currentInputLetter] -= 1;
            output.push_back('[');
            output.push_back(currentInputLetter);
            output.push_back(']');
            correctLettersAmount++;

        }
        // if the character is correct but in wrong position placve a {} around it, also checks if another of that character is present
        else if(letter_counts[currentInputLetter] > 0){
            letter_counts[currentInputLetter] -= 1;
            output.push_back('{');
            output.push_back(currentInputLetter);
            output.push_back('}');
        }
        else{
            output.push_back(currentInputLetter);
        }
    }

    output = output +" " + correctWord + '\n';

   /**
    *  If the guess is right then change status to WORDLE_COMPLETED
    *  if not reduce amount of tries left and print on screen
    * if tries left=0 set wordle status to stop
    */

    if(correctLettersAmount == (int) correctWord.size()){
        output += "Congrats thats the correct word! ";
        WordleCode::wordleStatus = WordleCode::WORDLE_COMPLETED;
    }
    else{
        WordleCode::triesLeft--;

        if(WordleCode::triesLeft == 0){
            output += "Out of attempts, say goodbye to the World ";
            WordleCode::wordleStatus = WordleCode::WORDLE_STOP;
        }
        else{
            output += WordleCode::triesLeft;
        }
    }

    return output;
}


WordleCode::Status WordleCode::getStatus(){
    return WordleCode::wordleStatus;
}
vector<string> WordleCode::getAllWords(){
    return WordleCode::allPossibleWords;
}

bool WordleCode::isEqualIgnoreCase(char& first, char& second){
    return tolower(first) == tolower(second);
}
