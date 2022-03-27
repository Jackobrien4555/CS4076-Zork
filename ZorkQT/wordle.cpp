#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include "wordle.h"
#include "ui_wordle.h"
#include <QTextStream>
#include <QFile>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#define SIZE (5)
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_RESET   "\x1b[0m"

using std::ifstream;
using std::getline;
using std::cout;
using std::endl;
using namespace std;

int verify_letter(int position, char c, string word, int file_size);
int count_all_words();
void print_all_words();
void welcome_message();
bool check_attempt(string attempt, int file_size);
string choose_random_word(int file_size);

ifstream in;

Wordle::Wordle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Wordle)
{
    ui->setupUi(this);
}

Wordle::~Wordle()
{
    delete ui;
}

int start(){
    int correct_letters = 0, attempts_num = 0, file_size = count_all_words();
        string right_word = choose_random_word(file_size);

        welcome_message();
        do {
            string attempt;
            cin >> attempt;
            if (!check_attempt(attempt, file_size))
                continue;
            int diff = 'A' - 'a';
            correct_letters = 0;
            for (int i = 0; i < SIZE; i++){
                switch (verify_letter(i, attempt[i], right_word, file_size)){
                    case -1:
                        printf("%c ", attempt[i] + diff);
                        break;
                    case 0:
                        printf(COLOR_YELLOW "%c " COLOR_RESET, attempt[i] + diff);
                        break;
                    case 1:
                        correct_letters++;
                        printf(COLOR_GREEN "%c " COLOR_RESET, attempt[i] + diff);
                        break;
                }
            }
            cout << "\n";
            attempts_num++;

        } while (correct_letters != 5 && attempts_num < 5);
        if (attempts_num == 5 && correct_letters != 5)
            cout << "Lost.The right word is: " << right_word << "\n";
        else
            printf(COLOR_GREEN "Congrats!!\n" COLOR_RESET);

        return 0;
    }

int verify_letter(int position, char c, string word, int file_size){
    int i, found = -1;
    if (word[position] == c)
        return 1;

    for (i = 0; i < SIZE; i++){
        if (word[i] == c){
            found = 0;
            break;
        }
    }
    return found;
}

int count_all_words(){
    string line;
    int count = 0;
    in.open("words.txt");

    while(in.peek()!=EOF){
        getline(in, line);
        count++;
    }
    in.close();
    return count;
}

void print_all_words(){
    string line;
    in.open("words.txt");
    while(in.peek()!=EOF){
        getline(in, line);
        cout << line << " ";
    }
    cout << "\n";
    in.close();
}

void welcome_message(){
    printf(COLOR_RED "\n\n                                        Welcome\n" COLOR_RESET);
    printf(COLOR_YELLOW "                                    W O R D L E\n\n" COLOR_RESET);
    printf(COLOR_GREEN "Type here:\n" COLOR_RESET);
    printf(COLOR_BLUE "    Help" COLOR_RESET);
    cout << " - to see the wordlist.\n";
    printf(COLOR_BLUE "    Quit" COLOR_RESET);
    cout << " - to leave the game.\n";
    printf(COLOR_BLUE "    Its a 5 letter word " COLOR_RESET);
    cout << "(in lowercase) - try to guess the answer.\n\n";
    printf(COLOR_YELLOW "                                 5 tries available\n" COLOR_RESET);

}
bool check_attempt(string attempt, int file_size){

    if (attempt.compare("quit") == 0)
        exit(EXIT_SUCCESS);
    else if (attempt.compare("help") == 0){
        print_all_words();
        return false;
    }
    string word;
    in.open("words.txt");
    for (int i = 0; i < file_size; i++){
        getline(in, word);
        if (attempt.compare(word) == 0){
            in.close();
            return true;
        }
    }
    in.close();
    cout << "Word doesn't exist\n";
    return false;
}

string choose_random_word(int file_size){
    string right_word;
    in.open(":/words.txt");

    srand((unsigned)time(0));
    for(int i = 0; i < rand() % file_size + 1; i++){
        getline(in, right_word);
    }
    in.close();
    if (right_word.length() != 5)
        exit(EXIT_FAILURE);

    return right_word;
}


void Wordle::on_Quit_clicked()
{
    Wordle::close();
}
void Wordle::on_Enter_clicked()
{
  start();
}
