#pragma once
#include "../../utils/logwrapper.h"
#include "datatype/int_metric.h"
#include <iostream>
#include <vector>

template <class T>
class Metric {

    private:

        std::string metric_name;

        std::vector<T> *metric_data;

    public:

        Metric(std::string metric_name);
        
        void print_metrics();

        void add_data(const T &data);

}; 