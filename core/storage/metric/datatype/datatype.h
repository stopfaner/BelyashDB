#pragma once

#include <ctime>
#include <string>

class DataType {
    
    public:

        uint32_t timestamp;

        DataType() {
            this->timestamp = std::time(0);
        }

        virtual std::string operator()() const = 0;


        uint32_t get_timestamp() {
            return this->timestamp;
        }

};