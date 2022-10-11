#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>

#include "src/Tokenizer.h"
#include "src/Interpreter.h"

Interpreter interpreter;

void debug_tokens(std::vector<std::vector<std::string>> tokens) {
    int counter = 1;

    for (auto line_tokens : tokens) {
        std::cout << "-> LINE NR: " << counter << " <-" << std::endl;

        for (auto token : line_tokens) {
            std::cout << token << std::endl;
        }

        std::cout << "------------------------" << std::endl;
        counter++;
    }
}

/**
 * Takes in the direction / file name of the src code and reads it in
 * as a single string
 * 
 * @param fullDir => Directory / file name of the .syc file that contains
 * the source code
 * @return std::string 
 */
std::string read_file(std::string fullDir)
{
    std::ifstream ifs;
    ifs.open(fullDir);

    if (!ifs.is_open()) {
        std::cerr << "Unkown file or directory";
    }

    return std::string((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
}

/**
 * Main function of the interpreter it takes in the console command and,
 * validates it and calls to further action
 * 
 * @param argc => amount of arguments given in the command
 * @param argv => actuall command given
 * @return int 
 */
int main(int argc, char *argv[])
{
    std::vector<std::string> argStr;

    for (int i = 0; i < argc; i++) {
        std::string arg;

        for (int j = 0; j < strlen(argv[i]); j++) {
            arg += argv[i][j];
        }

        if (arg == "Sync") {
            continue;
        }

        argStr.push_back(arg);
    }

    auto argIt = argStr.begin();

    if (*argIt != "interp") {
        std::cerr << "Unknown command: " << *argIt;
        return 0;
    }
    
    argStr.erase(argIt);
    argIt = argStr.begin();

    std::string path = *argIt;
    std::string recog = path.substr(1,1);
    std::string code = read_file(path);

    std::vector<std::vector<std::string>> tokens = tokenize(code);

    interpreter.interpret(tokens);
}