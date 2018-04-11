#pragma once

#include "../../utils/logwrapper.h"

#include "datatype/int_metric.h"
// #include "datatype/decimal_metric.h"
// #include "datatype/percentage_metric.h"

#include <iostream>
#include <vector>

#define MAX_BUFFER_SIZE 10

template <class T>
class Metric {

    private:

        std::string metric_name;
        std::string metric_tag;
        std::string metric_full_name;

        uint32_t buffer_size;

        std::shared_ptr<std::vector<T>> flush_buffer;

        std::shared_ptr<std::vector<T>> metric_data;


    public:

        Metric();
        Metric(std::string metric_name, std::string tag_name = "");
        Metric(const Metric<T> &metric);
        // // Metric(std::string metric_name, std::string tag_name = "",)

        // ~Metric();
        
        // void print_metrics();

        // void add_data(const T &data);

}; 