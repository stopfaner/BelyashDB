#include "request.h"

Request::Request() {
    this->request_str = NULL;
    this->session_id = NULL;
}

Request::~Request() {
    this->request_str = NULL;
    this->session_id = NULL;
}

void Request::set_request_str(char *request_str) {
    this->request_str = request_str;
}

void Request::set_session_id(char *session_id) {
    this->session_id = session_id;
}
