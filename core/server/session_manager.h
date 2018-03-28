#pragma once

#include <stdint.h>
#include <stdio.h> 
#include <string.h>   //strlen 
#include <stdlib.h> 
#include <map>
#include "uuid4.h"
#include "session.h"

#define MAX_CLIENTS_CONN 30

class SessionManager {

    private:

        uint32_t max_clients_count;

        // std::map<std::string, Session*> sessions;

        char buffer[1025]; 

        Session* generate_session(int session_socket);

        void add_session(Session *session);

    public:

        SessionManager(): max_clients_count(MAX_CLIENTS_CONN) {
        }
        SessionManager(uint32_t clients_count);
        ~SessionManager();

        void create_new_session(int session_socket);
        void remove_session(int session_socket);
        void push_in_session(char *data, int session_socket, int valread);
};