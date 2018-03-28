#include "session_manager.h"

SessionManager::SessionManager(uint32_t clients_count) {
    this->max_clients_count = clients_count;
}

SessionManager::~SessionManager() {

}

Session* SessionManager::generate_session() {

}

void SessionManager::add_session(Session *session) {

}

void SessionManager::create_new_session(int session_socket) {
    
}

void SessionManager::remove_session(int session_port) {

}

void SessionManager::push_in_session(char *data) {

}
