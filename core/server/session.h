#pragma once

#include <stdio.h> 
#include <string.h>   //strlen 
#include <stdlib.h> 
#include <unistd.h>   //close 
#include "uuid4.h"
#include <arpa/inet.h> 
#include <sys/socket.h> 

class Session {

    private:

        // UUID4 session_uuid;
        int session_socket;

        char buffer[1025]; 
    
    public:

        Session(UUID4 session_id, int session_socket) {
            // this->session_uuid = UUID4(session_id);
            this->session_socket = session_socket;
        }

        void accept(char *data, int valread) {
            strcpy(buffer, data);
            buffer[valread] = '\0';
            printf(buffer);
            send(session_socket, buffer, strlen(buffer), 0); 
        }

        void close_session(int session_socket) {
            close(session_socket);
        }
};