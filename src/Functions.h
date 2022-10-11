#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <map>

#include "Storage.h"

class Functions {
    public:
        Functions(Storage& store);
        bool isInbuildFunc(std::vector<std::string> token);

    private:
        Storage &storage;
        std::map<std::string, void (Functions::*)(std::string)> funcs = {
            {"print", print},
            {"printl", printl}
        };

        std::string usesVar(std::string arg);
        std::string getArg(std::string token);
        void print(std::string arg);
        void printl(std::string arg);
};
