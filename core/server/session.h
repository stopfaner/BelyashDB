#pragma once

#include <stdio.h> 
#include <string.h>   //strlen 
#include <stdlib.h> 
#include <unistd.h>   //close 
#include "uuid4.h"
#include <arpa/inet.h> 
#include <sys/socket.h> 
#include "../utils/logwrapper.h"

namespace server {

    class Session {

    private:

        // Logger instance for session
        Logger                  *logger;
        // UUID of current session
        UUID4                   session_uuid;
        // Session socket number
        int                     session_socket;
        // Session buffer of request
        char                    buffer[1025]; 
    
    public:

        // Constructor
        Session(UUID4 session_uuid, int session_socket);
        Session(const Session &other_session);
        ~Session();

        // Creating new session instance
        static Session*         open_session(int session_socket);
        // Accepting data from session manager
        void                    accept_request(char *data, int valread);
        // Closing current session
        void                    close_session(int session_socket);

        // Setters
        void                    set_session_socket(int session_socket);
        void                    ses_session_uuid(UUID4 session_uuid);

        // Getters
        int                     get_session_socket() const;
        UUID4                   get_session_uuid() const;
    };
}
