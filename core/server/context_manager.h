#pragma once
#include "context.h"


class ContextManager {

    private:

        Context *context;

    public:

        ContextManager();

        void set_context();

};