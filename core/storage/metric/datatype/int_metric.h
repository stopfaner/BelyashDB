#pragma once
#include "datatype.h"
#include <stdint.h>
#include <sstream>
#include <string>

class IntegerMetric: public DataType { 
    
    private:

        int32_t data;

    public:

        IntegerMetric(int32_t data) {
            this->data = data;
        }

        std::string operator()() const{
            std::stringstream ss;
            ss << this->timestamp << ": " << this->data;
            std::string s = ss.str();

            return s;
        }

        int32_t get_data() const{
            return this->data;
        }

};