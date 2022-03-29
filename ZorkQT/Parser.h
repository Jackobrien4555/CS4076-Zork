#ifndef PARSER_H_
#define PARSER_H_

#include "Command.h"
#include "CommandWords.h"

class Parser {
private:
    CommandWords *commands;

public:
    Parser();
    ~Parser();
    Command* getCommand();
    Command* convertToCommand(string input);
        string commandsInString();
    //void showCommands();
};
#endif //Parser.h
