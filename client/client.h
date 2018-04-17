#pragma once

#include<iostream>    //cout
#include<stdio.h> //printf
#include<string.h>    //strlen
#include<string>  //string
#include<sys/socket.h>    //socket
#include<arpa/inet.h> //inet_addr
#include<netdb.h>

#include "console_param.h"

#define DEFAULT_HOST "localhost"
#define DEFAULT_PORT 8888

class Client {
    
    private:

        int                     sock;
        
        std::string             address;

        uint32_t                port;

        struct sockaddr_in      server;

    public:

        Client();
        bool                    connect();
        bool                    send_request(std::string data);
        std::string             receive_response(int size=512);

        void                    set_address(std::string address);
        void                    set_port(uint32_t port);
};