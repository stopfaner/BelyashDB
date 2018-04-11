#include "metric.h"

template <class T>
Metric<T>::Metric() {

}

template <class T>
Metric<T>::Metric(std::string metric_name, std::string tag_name) {

}

template <class T>
Metric<T>::Metric(const Metric<T> &metric) {
    
}

// template <class T>
// Metric<T>::~Metric() {
//     // TODO: release 
// }

// template <class T>
// void Metric<T>::print_metrics() {
//     for (const T &metric: *metric_data) {
//         std::cout << metric() << std::endl;
//     }
// }

// template <class T>
// void Metric<T>::add_data(const T &data) {
//     metric_data->push_back(data);
// }

template class Metric<IntegerMetric>;
// template class Metric<DecimalMetric>;
// template class Metric<PercentageMetric>;
