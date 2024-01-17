#pragma once
#include "y_function.h"
#include "../y_value.h"

class var_function final : public y_function {
public:
    var_function();

    void execute(const std::string& var_name, const y_value& value);
};
