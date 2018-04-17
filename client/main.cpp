#include "client.h"
#include <stdlib.h> 
#include <sstream>


int main(int argc, char *argv[]) {

    // Console parameters
    std::string address = "";
    uint32_t port = 0;

    for (int i = 0; i < argc; i++) {
        if (std::strncmp(argv[i], addr_param.c_str(), 2) == 0) {
            if (address.length() == 0) {
                if (argc > i + 1) {
                    address = std::string(argv[i + 1]);
                    
                    i++;
                } else {
                    std::cout << "Not enough arguments to -a parameter." << std::endl;
                    exit(EXIT_FAILURE);
                }
            } else {
                std::cout << "Param -a has already been passed." << std::endl;
                exit(EXIT_FAILURE);
            }
        } else if(std::strncmp(argv[i], port_param.c_str(), 2) == 0) {
            if (port == 0) {
                if (argc > i + 1) {
                    std::stringstream value;
                    value << argv[i + 1];
                    value >> port;
                    i++;
                } else {
                    std::cout << "Not enough arguments to -p parameter." << std::endl;
                    exit(EXIT_FAILURE);
                }
            } else {
                std::cout << "Param -p has already been passed." << std::endl;
                exit(EXIT_FAILURE);
            }
        }
    }

    Client *client = new Client();

    // Setting connection address if provided
    if (address.length() != 0) {
        client->set_address(address);
    }

    // Setting connection port if provided
    if (port != 0) {
        client->set_port(port);
    }

    // Connecting to TCP server
    bool is_connected = client->connect();

    while (is_connected) {
        std::string data;

        std::cout << "belyash > ";
        std::cin >> data;
        client->send_request(data);
        std::cout << std::endl;

        std::string response = client->receive_response(1024);
        if (std::strncmp(response.c_str(), "quit", 4) == 0) {
            is_connected = false;
            break;
        }

        std::cout << response << std::endl;
    }

    return 0;
}