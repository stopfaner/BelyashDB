#include "metric_manager.h"

storage::MetricManager::MetricManager() {

}

storage::MetricManager::~MetricManager() {
    
}

storage::MetricManager* storage::MetricManager::get_manager()  {

    if (manager == 0) {
        manager = new MetricManager();
    }

    return manager;
}

bool storage::MetricManager::create_metric(const UUID4 &collection_uuid, std::string metric_name, std::string tag_name) {
    std::cout << "Creating metric logic here" << std::endl;
}

bool storage::MetricManager::delete_metric(const UUID4 &collection_uuid, std::string metric_name, std::string tag_name) {
    std::cout << "Deleting metric logic here" << std::endl;
}

storage::MetricManager* storage::MetricManager::manager = nullptr;
