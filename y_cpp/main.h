#pragma once
#include <vector>

#include "y_value.h"
#include "y_functions/y_function.h"

std::vector<y_function> parse_file(const char* filename);

y_function parse_line(const std::string& line);

y_value parse_value(const std::string& value);

y_value parse_string(const std::string& string);
