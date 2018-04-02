#pragma once

#define MAX_REQUEST_LENGTH 1024
#include "../utils/logwrapper.h"

class Request {

    private:

        char *request_str;
        char *session_id;

        bool err_flag = false;
        char *err = NULL;

    public:

        Request();
        
        ~Request();

        void set_session_id(char *session_id);
        void set_request_str(char *request_str);

        void get_session_id() const;
        void get_request_str() const;

};