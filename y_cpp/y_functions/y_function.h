#pragma once
#include <string>

#include "../y_type.h"

class y_function {
public:
    y_function() = default;
    virtual ~y_function() = default;

    std::string function_name;
    y_type* required_arguments;
};
