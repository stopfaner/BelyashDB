#include "input_parser.h"

InputParser::InputParser() {
    this->collection_manager = storage::CollectionManager::get_manager();
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

CollectionCase InputParser::_create_collection(std::string collection_name) {
    char *name = new char[collection_name.length() - 1];
    std::strcpy(name, collection_name.c_str());

    return this->collection_manager->create_collection(name);
}

CollectionCase InputParser::_delete_collection(std::string collection_name) {

}

std::string InputParser::_show_collections() {
    std::vector<storage::Collection> collections;
    this->collection_manager->get_collections(collections);

    std::stringstream ss;
    for (const storage::Collection &collection: collections) {
        ss << collection.get_name() << std::endl;
    }

    return ss.str();
}

char* InputParser::create_collection(char *command) {
    std::vector<std::string> parameters;
    this->get_parameters(command, std::strlen(CREATE_COLLECTION) - 1, parameters);

    switch(parameters.size()) {
        case 0: {
            return "Too few parameters. \n";
            break;
        }
        case 1: {
            CollectionCase is_success = this->_create_collection(parameters[0]);
            
            if (is_success == COLLECTION_CREATED){
                return "Collection was successfully created. \n";
            } else if (is_success == COLLECTION_EXIST) {
                return "Collection already exist. \n";
            }
            
            return "Something went wrong during collection creating. \n";
            break;
        }
        default: {
            return "Too many parameters passed. \n";
            break;
        }
    }
}

char* InputParser::delete_collection(char *command) {
     std::vector<std::string> parameters;
    this->get_parameters(command, std::strlen(DELETE_COLLECTION) - 1, parameters);

    switch(parameters.size()) {
        case 0: {
            return "Too few parameters. \n";
            break;
        }
        case 1: {
            CollectionCase is_success = this->_delete_collection(parameters[0]);
            
            if (is_success == COLLECTION_CREATED){
                return "Collection was successfully created. \n";
            } else if (is_success == COLLECTION_EXIST) {
                return "Collection already exist. \n";
            }
            
            return "Something went wrong during collection creating. \n";
            break;
        }
        default: {
            return "Too many parameters passed. \n";
            break;
        }
    }
}

char* InputParser::show_collections(char *command) {
    std::vector<std::string> parameters;
    this->get_parameters(command, std::strlen(SHOW_COLLECTIONS) - 1, parameters);
    
    switch (parameters.size()) {
        case 0: {
            std::string collections = this->_show_collections();
            if (collections.length() == 0) {
                return "No collections were found. \n";
            } else {
                char *data = new char[collections.length() - 1];
                std::strcpy(data, collections.c_str());

                return data;
            }
            break;
        }
        default: {
            return "Parameters are not required in this method. \n";
        }
    }
}

char* InputParser::accept_command(char *command) {

    
    if (std::strncmp(command, "exit()", 6) == 0) {
        return "quit \n";
    }

    if (std::strncmp(command, CREATE_COLLECTION, std::strlen(CREATE_COLLECTION) - 1) == 0) {
        return this->create_collection(command);
    }

    if (std::strncmp(command, SHOW_COLLECTIONS, std::strlen(SHOW_COLLECTIONS)) == 0) {  
        return this->show_collections(command);
    }

    if (std::strncmp(command, DELETE_COLLECTION, std::strlen(DELETE_COLLECTION) - 1) == 0) {
        return this->delete_collection(command);
    }

    return "Command not found. \n";
}