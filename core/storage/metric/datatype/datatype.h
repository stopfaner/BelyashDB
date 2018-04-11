#pragma once

#include <ctime>
#include <string>

class DataType {

    protected:

        // Timestamp of node
        uint32_t timestamp;
    
    public:

        DataType() {
            this->timestamp = std::time(0);
        }
        
        virtual ~DataType() {
            this->timestamp = 0;
        }

        virtual std::string operator()() const = 0;

        uint32_t get_timestamp() const {
            return this->timestamp;
        }
};