#include "main.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <codecvt>

#include "y_value.h"
#include "y_functions/y_function.h"

std::vector<y_function> defined_functions;

int main(const int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: y_cpp <filename>" << '\n';
        return 1;
    }

    parse_file(argv[1]);

    return 0;
}

std::vector<y_function> parse_file(const char* filename) {
    std::ifstream file(filename, std::ifstream::in | std::ifstream::binary);
    std::vector<y_function> functions;

    if (file.is_open()) {
        file.imbue(std::locale(std::locale(), new std::codecvt_utf8<char>));
        file.ignore(1);
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

    std::vector<y_value> arguments;
    bool is_string = false;

    std::string buffer_string;

    // TODO: Fix last value of file not being parsed if a space isn't present at the end of the line
    for (const char value : line) {
        if (!is_string && value == ' ') {
            arguments.push_back(parse_value(buffer_string));
            buffer_string = "";

        } else {
            if (!is_string && value == '"') {
                is_string = true;

            } else if (is_string && value == '"' && buffer_string.back() != '\\') {
                is_string = false;

                arguments.push_back(parse_string(buffer_string));
                buffer_string = "";
            }

            buffer_string += value;
        }
    }

    return {}; // TODO: Return parsed function
}

y_value parse_value(const std::string& value) {
    // Parse booleans
    if (value == "TRUE" || value == "FALSE") {
        return y_value{boolean, value};
    }

    // Parse int
    if (std::all_of(value.begin(), value.end(), isdigit)) {
        return y_value{number_int, value};
    }

    // Parse float
    bool is_float = true;
    for (const char c : value) {
        if (!isdigit(c) && c != '.') {
            is_float = false;
            break;
        }
    }

    if (is_float) {
        return y_value{number_float, value};
    }

    // Parse name
    auto first_char = [](const char c) { return isalpha(c) || c == '_'; };
    auto other_chars = [](const char c) { return isalnum(c) || c == '_'; };

    if (std::all_of(value.begin(), value.begin() + 1, first_char) &&
        std::all_of(value.begin() + 1, value.end(), other_chars)) {

        return y_value{var_name, value};
    }

    throw std::runtime_error("Failed to parse value");
}

y_value parse_string(const std::string& string) {
    return y_value{y_type::string, string.substr(1, string.size() - 2)};
}
