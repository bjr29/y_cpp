#include "var_function.h"

#include "../y_value.h"

var_function::var_function() {
    function_name = "VAR";
    required_arguments = new y_type[2]{var_name, value};
}

void var_function::execute(const std::string& var_name, const y_value& value) {
    
}
