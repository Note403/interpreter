#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <map>

class Storage {
    public:
        Storage(void);
        std::map<std::string, int> integers;
        std::map<std::string, double> doubles;
        std::map<std::string, std::string> strings;
        std::map<std::string, char> chars;
        std::vector<std::string> data_types {
            "int",
            "double",
            "string",
            "char"
        };

        void addInt(std::string name, int value);  
        void addDouble(std::string name, double value);
        void addString(std::string name, std::string value);
        void addChar(std::string name, char value);   
};