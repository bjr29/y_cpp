#include "y_value.h"

#include <stdexcept>

template <typename T>
T y_value::get_value() {
    switch (type) {
        case number_int:
            return std::stoi(value);
        
        case number_float:
            return std::stof(value);

        case string:
            return value;
        
        case boolean:
            return value == "TRUE";
        
        case var_name:
            return value;
        
        default:
            throw std::runtime_error("Failed to get value");
    }
}
