#pragma once

#include <string>

#include "y_type.h"

class y_value {
public:
    y_type type;
    std::string value;

    template <typename T>
    T get_value();
};
