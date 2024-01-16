#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "main.h"

// const y_function builtin_functions[] = {
//     new y_function()
// };

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: y_cpp <filename>" << '\n';
        return 1;
    }
    
    parse_file(argv[1]);
    
    return 0;
}

std::vector<y_function> parse_file(const char* filename) {
    std::ifstream file(filename);
    std::vector<y_function> functions;

    if (file.is_open()) {
        std::string code_line;

        while (std::getline(file, code_line)) {
            y_function parsed_function = parse_line(code_line);
            functions.push_back(parsed_function);
        }

        file.close();
    } else {
        std::cout << "Unable to open file" << '\n';
    }

    return functions;
}

y_function parse_line(const std::string& line) {
    if (line.empty()) {
        return {};
    }

    std::vector<y_type> arguments;
    bool is_string = false;

    std::string buffer_string;
    
    for (const char value : line) {
        if (!is_string && value == ' ') {
            // TODO: Parse argument
            
        } else {
            if (!is_string && value == '"') {
                is_string = true;
                
            } else if (is_string && value == '"') {
                is_string = false;
                
            }

            buffer_string += value;
        }
    } 
    
    return {};
}
