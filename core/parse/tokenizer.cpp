#include <stddef.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

class Tokenizer {

    private:
        char* input_command;
        size_t command_size;

        bool err_flag = false;
        char* err = NULL;
        
    public:

        Tokenizer() {
            this->input_command = NULL;
            this->command_size = 0;

            std::cout << "Tokenizer initialized" << std::endl;
        }

        void accept_command(char* command) {
            
            if (strcmp(command, "exit()") == 0) {
                exit(EXIT_SUCCESS);
            } else {
                std::cout << command << std::endl;
            }
        }

};