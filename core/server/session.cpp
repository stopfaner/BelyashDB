#include "session.h"

server::Session::Session(UUID4 session_uuid, int session_socket) {
    this->session_uuid = UUID4(session_uuid);
    this->session_socket = session_socket;

    this->init_loader();
}

server::Session::Session(const Session &other_session) {
    this->session_uuid = other_session.get_session_uuid();
    this->session_socket = other_session.get_session_socket();
    
    this->init_loader();
}

void server::Session::init_loader() {

    logger = Logger::getLogger();
    logger->info("Setting up session");

    this->input_parser = new InputParser();
    this->context_manager = new ContextManager();
}

server::Session::~Session() {
    delete input_parser;
    delete context_manager;
}

server::Session* server::Session::open_session(int session_socket) {
    
    // session UUID
    UUID4 session_uuid = UUID4::generate();
    Session *session = new Session(session_uuid, session_socket);

    if (session == 0) {
        return NULL;
    }

    return session;
}

void server::Session::accept_request(char *data, int valread) {
    strcpy(buffer, data);
    buffer[valread] = '\0';

    printf(buffer);

    char *answer = this->input_parser->accept_command(buffer);
    if (std::strncmp(answer, "exit", 4) == 0) {
        this->close_session(this->session_socket);
        send(session_socket, answer, strlen(answer), 0);
    }

    else 
        send(session_socket, answer, strlen(answer), 0);
    // send(session_socket, parser_answer, strlen(parser_answer), 0); 
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