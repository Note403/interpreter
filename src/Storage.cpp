#include "Storage.h"

Storage::Storage(void) {}

void Storage::addInt(std::string name, int value) {
    integers[name] = value;
}

void Storage::addDouble(std::string name, double value) {
    doubles[name] = value;   
}

void Storage::addString(std::string name, std::string value) {
    strings[name] = value;
}

void Storage::addChar(std::string name, char value) {
    chars[name] = value;
}
