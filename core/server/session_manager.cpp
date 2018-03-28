#include "session_manager.h"

SessionManager::SessionManager(uint32_t clients_count) {
    this->max_clients_count = clients_count;
}

SessionManager::~SessionManager() {

}

Session* SessionManager::generate_session(int session_socket) {
    // generating session UUID
    UUID4 session_uuid = UUID4::generate();
    printf("session id");
    char uuid_str[37];      // ex. "1b4e28ba-2fa1-11d2-883f-0016d3cca427" + "\0"
    uuid_unparse_lower(session_uuid.uuid, uuid_str);
    printf("generate uuid=%s\n", uuid_str);
    // printf(session_uuid.uuid);
    // Session *session = new Session(NULL, session_socket);

    return NULL;
}

void SessionManager::add_session(Session *session) {

}

void SessionManager::create_new_session(int session_socket) {
    Session* session = this->generate_session(session_socket);
}

void SessionManager::remove_session(int session_socket) {
}

void SessionManager::push_in_session(char *data, int session_socket, int valread) {
}
