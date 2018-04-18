#pragma once
#include <string>
#include <string.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include "statement.h"
#include <boost/algorithm/string.hpp>

#include "../storage/collection/collection_manager.h"
#include "../storage/collection_utils.h"

class InputParser {

    private:

        std::shared_ptr<storage::CollectionManager>      collection_manager;


        void                                            get_parameters(char *command, uint16_t command_length, std::vector<std::string> &vec);

        CollectionCase                                  _create_collection(std::string collection_name);
        CollectionCase                                  _delete_collection(std::string collection_name);
        std::string                                     _show_collections();

        char*                                           create_collection(char *command);
        char*                                           delete_collection(char *command);
        char*                                           show_collections(char *command);

    public:

        InputParser();

        char* accept_command(char *command);
};