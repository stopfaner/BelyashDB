#include "input_parser.h"

InputParser::InputParser() {

}

void InputParser::get_parameters(char *command, uint16_t command_length, std::vector<std::string> &vec) {

    std::string str(command);
    std::stringstream paremeters(str.substr(command_length, str.find(')') - command_length));

    std::string parameter;
    while (std::getline(paremeters, parameter, ',')) {
        boost::trim(parameter);
        vec.push_back(parameter);
    }
}

int InputParser::accept_command(char *command) {

    
    if (std::strncmp(command, "exit()", 6) == 0) {
        return 0;
    }

    if (std::strncmp(command, "create_collection(", 18) == 0) {
        
        std::vector<std::string> params;
        this->get_parameters(command, 18, params);
        for (const std::string &param: params) {
            std::cout << param << std::endl;
        }

        return 0;
    }

    return 1;
}