#pragma once
#include "y_function.h"

std::vector<y_function> parse_file(const char* filename);
y_function parse_line(const std::string& line);
