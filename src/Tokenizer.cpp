#include <iostream>
#include <vector>
#include <cstring>

void debug_str_vec(std::vector<std::string> stuff) {
    for (std::string str : stuff) {
        std::cout << str << std::endl;
    }
}

/**
 * Takes in the source code as single string and splits it into
 * lines
 * 
 * @param code => Source code as single string 
 * @return std::vector<std::string> 
 */
std::vector<std::string> split_by_line(std::string code) {
    std::vector<std::string> lines;

    std::string delimiter = "\n";
    std::string::size_type position = 0;
    std::string::size_type previous = 0;

    while ((position = code.find(delimiter, previous)) != std::string::npos) {
        lines.push_back(code.substr(previous, position - previous));
        previous = position + delimiter.size();
    }

    lines.push_back(code.substr(previous));

    return lines;
}

/**
 * Takes the source code which has already been split into lines and splits
 * those lines into single tokens
 * 
 * @param lines => Data object that contains the source code split into lines
 * @return std::vector<std::vector<std::string>> 
 */
std::vector<std::vector<std::string>> split_lines(std::vector<std::string> lines) {
    std::vector<std::vector<std::string>> tokens;
    bool inside_brack = false;

    for (auto line : lines) {
        if (line.at(0) == '/' && line.at(1) == '/') {
            continue;
        }

        if (line == "") {
            continue;
        }

        std::vector<std::string> line_tokens;
        std::string token;
        int position = 0;

        while (position < line.length()) {
            if (!inside_brack) {
                if (line.at(position) == '(') {
                    inside_brack = true;
                }
            }
            
            if (inside_brack) {
                token.push_back(line.at(position));

                if (line.at(position) == ')') {
                    inside_brack = false;
                    line_tokens.push_back(token);
                    token = "";
                }
            } else {
                if (line.at(position) != ' ' && line.at(position) != ';') {
                    token.push_back(line.at(position));
                } else {
                    if (token == "\n") {
                        token = "";
                    } else {
                        line_tokens.push_back(token);
                        token = "";
                    }
                }
            }

            position++;
        }

        tokens.push_back(line_tokens);
    }

    return tokens;
}

/**
 * Main function of the tokenizer takes in the code as a single string and
 * calls further functions to return a data object that has the code split up
 * into single lines and those lines into arguments / tokens
 * 
 * @param code => Source code as a single string
 * @return std::vector<std::vector<std::string>> 
 */
std::vector<std::vector<std::string>> tokenize(std::string code) {
    std::vector<std::string> lines = split_by_line(code);

    return split_lines(lines);
}