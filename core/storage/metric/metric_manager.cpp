#include "metric_manager.h"

storage::MetricManager::MetricManager() {

}

storage::MetricManager::~MetricManager() {
    
}

std::shared_ptr<storage::MetricManager> storage::MetricManager::get_manager()  {

    if (manager.get() == 0) {
        manager = std::make_shared<MetricManager>();
    }

    return manager;
}

bool storage::MetricManager::create_metric(const UUID4 &collection_uuid, std::string metric_name, std::string tag_name) {
    std::cout << "Creating metric logic here" << std::endl;
}

bool storage::MetricManager::delete_metric(const UUID4 &collection_uuid, std::string metric_name, std::string tag_name) {
    std::cout << "Deleting metric logic here" << std::endl;
}

bool storage::MetricManager::load_metrics(std::string collection_name, std::vector<std::shared_ptr<Metric<DataType>>> &metrics) {
    
}

std::shared_ptr<storage::MetricManager> storage::MetricManager::manager = nullptr;
