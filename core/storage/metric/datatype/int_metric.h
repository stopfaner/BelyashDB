#pragma once
#include "datatype.h"
#include <stdint.h>
#include <sstream>
#include <string>

class IntegerMetric: public DataType { 
    
    private:
        
        int64_t data;

    public:

        IntegerMetric(int64_t data) {
            this->data = data;
        }

        IntegerMetric(const IntegerMetric &metric) {
            this->timestamp = metric.get_timestamp();
            this->data = metric.get_data();
        }

        std::string operator()() const{
            std::stringstream ss;
            ss << this->timestamp << ": " << this->data;
            std::string s = ss.str();

            return s;
        }

        int64_t get_data() const{
            return this->data;
        }

        void set_data(int64_t data) {
            this->data = data;
        }

};