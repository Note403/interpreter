#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "Storage.h"
#include "Functions.h"
#include "Tokenizer.h"

class Interpreter {
    public:
        Interpreter(void);
        void interpret(std::vector<std::vector<std::string>> code);

    private:
        Storage store;
        Functions functions = Functions(store);
        void createVar(std::string type, std::string name, std::string value);
        std::string getType(std::string arg);
        bool isVar(std::vector<std::string> arg);
        void debug_memory();
};
