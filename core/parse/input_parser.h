#pragma once
#include <string>
#include <string.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include "statement.h"
#include <boost/algorithm/string.hpp>

class InputParser {

    private:
        
        void get_parameters(char *command, uint16_t command_length, std::vector<std::string> &vec);

    public:

        InputParser();

        int accept_command(char *command);
};