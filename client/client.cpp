#include "client.h"

Client::Client(): sock(-1), port(DEFAULT_PORT), address(DEFAULT_HOST)
{
}

bool Client::connect() {

    if (this->sock == -1) {
        this->sock = socket(AF_INET, SOCK_STREAM, 0);

        if (this->sock == -1) {
            std::cout << "Cannot create socket. \n";
        }
    } 

    if (inet_addr(address.c_str()) == -1) {

        struct hostent *he;
        struct in_addr **addr_list;

        if ((he = gethostbyname(this->address.c_str())) == NULL) {
            
            herror("gethostbyname");
            std::cout << "Failed to resolve hostname. \n" << std::endl;
             
            return false;
        }

        addr_list = (struct in_addr **) he->h_addr_list;

        for(int i = 0; addr_list[i] != NULL; i++) {
            server.sin_addr = *addr_list[i];
            std::cout << this->address << " resolved to " << inet_ntoa(*addr_list[i]) << std::endl;
            break;
        }
    } else {
        server.sin_addr.s_addr = inet_addr(address.c_str());
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    if (::connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0) {
        perror("connect failed. Error");
        return false;
    }
     
    std::cout << "Connected. \n" << std::endl;
    return true;
}

bool Client::send_request(std::string data) {

    //Send some data
    if(send(sock, data.c_str(), strlen(data.c_str()), 0) < 0) {
        perror("Send failed : ");
        return false;
    }
     
    return true;    
}

std::string Client::receive_response(int size) {
    char buffer[size];
    std::string reply;
     
    //Receive a reply from the server
    if( recv(sock , buffer , sizeof(buffer) , 0) < 0)
    {
        puts("recv failed");
    }
     
    reply = buffer;
    return reply;
}

void Client::set_address(std::string address) {
    this->address = address;
}

void Client::set_port(uint32_t port) {
    this->port = port;
}