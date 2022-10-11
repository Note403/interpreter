#include "Interpreter.h"

Interpreter::Interpreter(void) {}

/**
 * Main function of the Interpreter part. Takes in the code and parses each line
 * and executes the parsed line or gives out an error message.
 * 
 * @param code => Code of the src file split into lines and each line
 * is split into single words
 * @return void
 */
void Interpreter::interpret(std::vector<std::vector<std::string>> code) {
    std::cout << code.at(1)[0] << std::endl;
    
    for (auto line : code) {
        std::cout << line[0] << std::endl;

        if (functions.isInbuildFunc(line)) {
            continue;
        }

        if (isVar(line)) {
            continue;
        }
    }

    debug_memory();
}

void Interpreter::createVar(std::string type, std::string name, std::string value = "") {
    if (type == "int") {
        if (value == "") {
            store.addInt(name, 0);
        } else {
            store.addInt(name, atoi(value.c_str()));
        }
    } else if (type == "double") {
        if (value == "") {
            store.doubles[name] = 0.0;
        } else {
            store.doubles[name] = std::stod(value.c_str());
        }
    } else if (type == "char") {
        store.chars[name] = value.c_str()[1];
    } else if (type == "string") {
        std::cout << "Add String" << std::endl;
        store.addString(name, value.substr(1, value.length() - 2));
    }
}

std::string Interpreter::getType(std::string arg) {
    for (auto type : store.data_types) {
        if (arg == type) {
            return type;
        }
    }

    return "NO_TYPE";
}

/**
 * Checks if the current argument is a variable declaration
 * if it is the variable will be created and stored
 * 
 * @param arg => the argument in question
 * @return bool 
 */
bool Interpreter::isVar(std::vector<std::string> arg) {
    if (arg.size() == 2) {
        std::string type = getType(arg.at(0));
        
        if (type == "NO_TYPE") {
            return false;
        }

        createVar(type, arg.at(1));
        return true;
    }

    if (arg.size() == 4) {
        std::string type = getType(arg.at(0));

        if (type == "NO_TYPE") {
            return false;
        }

        createVar(type, arg.at(1), arg.at(3));
        return true;
    }

    return false;
}

void Interpreter::debug_memory() {
    std::map<std::string, int>::iterator int_it;
    std::map<std::string, double>::iterator double_it;
    std::map<std::string, std::string>::iterator string_it;
    std::map<std::string, char>::iterator char_it;

    std::cout << "--- INTEGERS ---" << std::endl;

    for (int_it = store.integers.begin(); int_it != store.integers.end(); int_it++) {
        std::cout << int_it->first + " " << int_it->second << std::endl;
    }

    std::cout << "--- DOUBLES ---" << std::endl;

    for (double_it = store.doubles.begin(); double_it != store.doubles.end(); double_it++) {
        std::cout << double_it->first + " " << double_it->second << std::endl;
    }

    std::cout << "--- STRINGS ---" << std::endl;

    for (string_it = store.strings.begin(); string_it != store.strings.end(); string_it++) {
        std::cout << string_it->first + " " << string_it->second << std::endl;
    }

    std::cout << "--- CHARS ---" << std::endl;

    for (char_it = store.chars.begin(); char_it != store.chars.end(); char_it++) {
        std::cout << char_it->first + " " << char_it->second << std::endl;
    }
}
