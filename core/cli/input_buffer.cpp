#include <stddef.h>
#include <iostream>
#include <stdio.h>

class InputBuffer
{
    private:
        char *buffer;
        size_t buffer_length;
        size_t input_length;

        void print_prompt() {
            std::cout << "belyash > ";
        }

        void read_input_command() {
            size_t bytes_read = getline(&(this->buffer), &(this->buffer_length), stdin); 
            
            if (bytes_read <= 0) {
                std::cout << "Error reading input.\n";
                
                this->err = "Error while reading input.";
                this->err_flag = true;
            }

            this->input_length = bytes_read - 1;
            this->buffer[bytes_read - 1] = 0;

            std::cout << this->buffer << std::endl;
        }

    public:
        bool err_flag = false;
        char *err = NULL;

        // Initial constructor
        InputBuffer() {
            this->buffer = NULL;
            this->buffer_length = 0;
            this->input_length = 0;
        }

        void listen() {
            while (!this->err_flag) {
                this->print_prompt();
                this->read_input_command();

            }
        }
};
        