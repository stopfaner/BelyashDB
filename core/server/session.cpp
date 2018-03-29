#include "session.h"

server::Session::Session(UUID4 session_uuid, int session_socket) {
    this->session_uuid = UUID4(session_uuid);
    this->session_socket = session_socket;
}

server::Session::Session(const Session &other_session) {
    this->session_uuid = other_session.get_session_uuid();
    this->session_socket = other_session.get_session_socket();
}

server::Session* server::Session::open_session(int session_socket) {
    
    // session UUID
    UUID4 session_uuid = UUID4::generate();
    Session *session = new Session(session_uuid, session_socket);

    if (session == 0) {
        printf("Cannot create new session.");
        return NULL;
    }

    return session;
}

void server::Session::accept_request(char *data, int valread) {
    strcpy(buffer, data);
    buffer[valread] = '\0';
    printf(buffer);
    send(session_socket, buffer, strlen(buffer), 0); 
}

void server::Session::close_session(int session_socket) {
    close(session_socket);
}

int server::Session::get_session_socket() const{
    return this->session_socket;
}

UUID4 server::Session::get_session_uuid() const{
    return this->session_uuid;
}