#include "Functions.h"

Functions::Functions(Storage& store): storage(store) {}

/**
 * Checks if the token represents an inbuild function of the language
 * 
 * @param token => Token in question
 * @return bool 
 */
bool Functions::isInbuildFunc(std::vector<std::string> token) {
    std::string name;
    int pos = 0;

    while (pos < token.at(0).length()) {
        if (token.at(0).at(pos) != '(') {
            name.push_back(token.at(0).at(pos));
        } else {
            pos = token.at(0).length();
        }
        
        pos++;
    }

    //this->*funcs[name](getArg(token.at(0)));

    return true;
}

std::string Functions::usesVar(std::string arg) {
    if (storage.integers.count(arg) != 0) {
        return "int";
    }

    if (storage.doubles.count(arg) != 0) {
        return "double";
    }

    if (storage.strings.count(arg) != 0) {
        return "string";
    }

    if (storage.chars.count(arg) != 0) {
        return "chars";
    }

    return "none";
}

/**
 * Gets the argument out of the token so the inbuild function
 * can be called
 * 
 * @param token => Token in question
 * @return std::string 
 */
std::string Functions::getArg(std::string token) {
    int start = token.find('(');
    int end = token.find(')');

    std::string arg = token.substr(start + 1, end - start - 1);

    if (arg.at(0) == '"') {
        start = arg.find('"');
        end = arg.find_last_of('"');

        arg = arg.substr(start + 1, end - start - 1);
    }

    return arg;
}

/**
 * print function of the language, takes in the string to print and does
 * a line break if the string ends with \n
 * 
 * @param arg => string to print
 */
void Functions::print(std::string arg) {
    std::string linebr;

    linebr.insert(0, 1, arg.at(arg.length() - 1));
    linebr.insert(0, 1, arg.at(arg.length() - 2));

    std::string var = usesVar(arg);

    std::map<std::string, std::string> strings;

    std::cout << strings.size() << std::endl;

    if (linebr == "\\n") {
        if (var != "none") {
            if (var == "int") {
                std::cout << storage.integers[arg];
            } else if (var == "double") {
                std::cout << storage.doubles[arg];
            } else if (var == "string") {
                std::cout << storage.strings[arg];
            } else if (var == "char") {
                std::cout << storage.chars[arg];
            }
        } else {
            std::cout << arg.substr(0, arg.length() - 2) << std::endl;
        }
    } else {
        std::cout << arg;
    }
}

/**
 * PrintLine function of the language, takes in the string to print and does
 * a line break after it got printed
 * 
 * @param arg => string to print
 */
void Functions::printl(std::string arg) {
    std::cout << arg << std::endl;
}
