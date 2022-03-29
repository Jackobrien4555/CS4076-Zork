#include "wordleCode.h"
#include <QTextStream>
#include <QFile>
#include <wordle.h>
//#include "dialogues.h"

using std::ifstream;
using std::getline;
using std::cout;
using std::endl;

vector<string> WordleCode::allWords;
int WordleCode::triesLeft;
WordleCode::gameStatus WordleCode::wordleStatus = WordleCode::WORDLE_STOP;
string WordleCode::targetWord;

bool WordleCode::isEqualIgnoreCase(char& first, char& second){
    return tolower(first) == tolower(second);
}

void WordleCode::initWords(string filename){
    if(filename.empty()){
        string text;

        QFile file(":/words.txt");
        QTextStream in(&file);
        if (file.open(QFile::ReadOnly | QFile::Text)){
            while(!in.atEnd()){
                //qDebug() << in.readLine();
                WordleCode::allWords.push_back(in.readLine().toStdString());
            }

        }

        file.close();
    }
}

void WordleCode::initialiseWordleEngine(){
    initWords("");
    WordleCode::wordleStatus = WordleCode::WORDLE_PROGRESS;
}

string WordleCode::evaluateInput(const string &input){
    string output = "";
    std::unordered_map<char, int> letter_counts;
    string correctWord = WordleCode::targetWord;
    int correctLettersAmount = 0;

    if(input.size() != correctWord.size()){
        return "";
    }

    // Initialising the letter_counts map, pairing each letter with 1
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

        // If the character is at the correct index
        if(WordleCode::isEqualIgnoreCase(currentInputLetter, correctWord.at(i))){
            letter_counts[currentInputLetter] -= 1;
            output.push_back('[');
            output.push_back(currentInputLetter);
            output.push_back(']');
            correctLettersAmount++;

        }
        // If the character exists but is in the wrong index
        // In this case, we also check the letter_counts map to see if there are any of that particular letter remaining.
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

    // If the guess is correct, set status to success
    if(correctLettersAmount == (int) correctWord.size()){
        output += "Congrats thats the correct word! ";
        WordleCode::wordleStatus = WordleCode::WORDLE_SUCCESS;
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

vector<string> WordleCode::getAllWords(){
    return WordleCode::allWords;
}

void WordleCode::startWordleGame(){
    // Randomising
    srand(time(NULL));
    WordleCode::triesLeft = 5;
    // Get a random word
    WordleCode::targetWord = allWords.at(rand() % allWords.size());
}

WordleCode::gameStatus WordleCode::getWordleStatus(){
    return WordleCode::wordleStatus;
}
