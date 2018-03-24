#include "core/cli/input_buffer.cpp"
#include <iostream>

using namespace std;

int main() 
{
    InputBuffer* input_buffer = new InputBuffer();

    while (!input_buffer->err_flag) {

        // reading input commands from user
        input_buffer->listen();
    }

    return 0;
}