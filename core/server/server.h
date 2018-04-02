#pragma once


#include <stdio.h> 
#include <string.h>   //strlen 
#include <stdlib.h> 
#include <errno.h> 
#include <unistd.h>   //close 
#include <arpa/inet.h>    //close 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <sys/time.h> //FD_SET, FD_ISSET, FD_ZERO macros 
#include <iostream>

#include "session_manager.h"

#define TRUE   1 
#define FALSE  0 
#define PORT 8888 
#define MAX_CLIENTS_DEFAULT 30
#define MAX_CLIENTS 100

namespace server {

    class Server {
        
        private:

            int opt = TRUE;  
            int master_socket;
            int address_len;
            int new_socket;
            int *client_socket;
            int max_clients;
            int activity;
            int valread;
            int sd;  

            int max_sd;  
            struct sockaddr_in server_address;

            // Session manager define
            SessionManager* session_manager;  
                
            char buffer[1025];  //data buffer of 1K 
                
            //set of socket descriptors 
            fd_set readfds;  
            
            bool err_flag = false;
            char *err = NULL;

            bool _set_up_socket();

            void _incomming_connection();
            void _io_accept();

        public:

            Server(int max_clients);

            void start_accepting();
    };
}