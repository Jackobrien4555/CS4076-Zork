#ifndef WORDLECODE_H
#define WORDLECODE_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using std::string;
using std::vector;



class WordleCode{
public:
    enum gameStatus {WORDLE_STOP, WORDLE_PROGRESS, WORDLE_FAIL, WORDLE_SUCCESS };

private:
    // All valid words
    static vector<string> allWords;
    static int triesLeft;    
    static gameStatus wordleStatus;
    static void initWords(string filename);
    static string targetWord;


public:
    static string evaluateInput(const string& input);
    static vector<string> getAllWords();
    static gameStatus getStatus();
    static void startWordleGame();
    static string checkGame();
    static void initialiseWordle();
    static bool isEqualIgnoreCase(char& first, char& second);
};

#endif // WORDLECODE_H
