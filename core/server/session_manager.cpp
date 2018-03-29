#include "session_manager.h"

server::SessionManager::SessionManager(uint32_t clients_count) {
    this->max_clients_count = clients_count;
}

server::SessionManager::~SessionManager() {
    sessions.clear();
}

server::Session* server::SessionManager::generate_session(int session_socket) {
    // generating session UUID
    UUID4 session_uuid = UUID4::generate();
    printf("session id");
    // char uuid_str[37];      // ex. "1b4e28ba-2fa1-11d2-883f-0016d3cca427" + "\0"
    // uuid_unparse_lower(session_uuid.uuid, uuid_str);
    // printf("generate uuid=%s\n", uuid_str);
    // printf(session_uuid.uuid);
    server::Session *session = server::Session::open_session(session_socket);

    if (session != 0) {
        return session;
    } else {
        return NULL;
    }
}

void server::SessionManager::add_session(Session *session, int session_socket) {
    if (session != 0) {
        sessions.insert(std::make_pair(session_socket, session));

        printf("Session for socket: %d was successfully created.", session_socket);
    } else {
        printf("Cannot create session for socket: %d ", session_socket);
    }
}

void server::SessionManager::create_new_session(int session_socket) {
    if (sessions.size() == max_clients_count) {
        printf("Cannot create new session. Max clients count exceeded.");
        return;
    } else {
        Session *session = this->generate_session(session_socket);

        this->add_session(session, session_socket);
    }
}

void server::SessionManager::remove_session(int session_socket) {
    if (sessions.find(session_socket) != sessions.end()) {
        Session *session = sessions[session_socket];
        sessions.erase(session_socket);
        delete session;

        printf("Session for socket: %d was successfully shut down.", session_socket);
    } else {
        printf("Cannot delete session, because it does not exist.");
    }
}

void server::SessionManager::push_in_session(char *data, int session_socket, int valread) {
    if (sessions.find(session_socket) != sessions.end()) {
        Session *session = sessions[session_socket];

        session->accept_request(data, valread);
    }
}
