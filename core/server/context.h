#pragma once
#include <memory>


enum ContextType {
    COMMON,
    COLLECTION,
    METRIC
};

class Context {

    private:

        ContextType         type;

        // std::shared_ptr<T>  context;

    public:
        Context();
};