#include "core/cli/input_buffer.cpp"
#include "core/utils/logwrapper.h"
#include <iostream>

using namespace std;

int main() 
{
    InputBuffer* input_buffer = new InputBuffer();
	Logger *logger = Logger::getLogger("test");

	// logger->info("some text");

    // reading input commands from user
    input_buffer->listen();

    return 0;
}