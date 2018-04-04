#include "metric.h"

template <class T>
Metric<T>::Metric(std::string metric_name) {
    this->metric_name = metric_name;
    this->metric_data = new std::vector<T>();
}

template <class T>
void Metric<T>::print_metrics() {
    for (const T &metric: *metric_data) {
        std::cout << metric() << std::endl;
    }

}

template <class T>
void Metric<T>::add_data(const T &data) {
    metric_data->push_back(data);
}

template class Metric<IntegerMetric>;
