#pragma once

#include <stdio.h> 
#include <string.h>   //strlen 
#include <stdlib.h> 
#include <unistd.h>   //close 
#include "uuid4.h"
#include <arpa/inet.h> 
#include <sys/socket.h> 

namespace server {

    class Session {

    private:

        UUID4 session_uuid;
        int session_socket;

        char buffer[1025]; 
    
    public:

        Session(UUID4 session_uuid, int session_socket);
        Session(const Session &other_session);

        static Session* open_session(int session_socket);

        void accept_request(char *data, int valread);
        void close_session(int session_socket);

        void set_session_socket(int session_socket);
        void ses_session_uuid(UUID4 session_uuid);

        int get_session_socket() const;
        UUID4 get_session_uuid() const;
    };
}
