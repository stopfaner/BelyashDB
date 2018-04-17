#include "collection.h"

storage::Collection::Collection() {
    // metric_manager = MetricManager::get_manager();
    
}


storage::Collection::Collection(std::string name, std::string uuid) {
    this->collection_name = name;
    this->collection_uuid = uuid;
    this->_initialize();
}

storage::Collection::Collection(std::string name, const storage::CollectionMetadata &metadata) {
    this->collection_name = name;
    this->collection_uuid = metadata.get_filename();   
    this->_initialize();
}

storage::Collection::Collection(const storage::Collection &collection) {
    this->collection_name = collection.get_name();
    this->collection_uuid = collection.get_uuid();
    this->_initialize();
}


void storage::Collection::_initialize() {
    this->logger = Logger::getLogger();
    this->metrics = std::make_shared<std::map<std::string, Metric<DataType>>>();
    this->metric_metadata = new std::map<std::string, MetricMetadata>();

    this->file_manager = std::make_shared<FileManager<MetricMetadata>>(this->collection_uuid);
    this->_load_metrics_metadata();
}

storage::Collection::~Collection() {
    this->metrics->clear();
    // this->metric_manager = nullptr;
}

std::string storage::Collection::get_name() const {
    return this->collection_name;
}

std::string storage::Collection::get_uuid() const {
    return this->collection_uuid;
}

std::map<std::string, Metric<DataType>> storage::Collection::get_metrics() const {

}

std::map<std::string, Metric<DataType>> storage::Collection::get_metric(std::string name) const {

}

bool storage::Collection::_load_metrics_metadata() {
    std::vector<MetricMetadata> vector;
    bool is_success = this->file_manager->read_all_data(vector);

    if (is_success) {
        logger->info("Metrics metadata was successfully loaded.");
    } else {
        logger->warn("Metrics metadata file is empty.");
    }

    for (const MetricMetadata &metadata: vector) {
        
        std::cout << metadata.get_metric_name() <<std::endl;

        this->metric_metadata->insert(std::make_pair(this->get_metric_name(metadata.get_metric_name(), metadata.get_tag_name()), metadata));
    }

    this->_load_metrics();
}

bool storage::Collection::_load_metrics() {
    std::cout << "Loading metrics" << std::endl;
}



std::string storage::Collection::get_metric_name(std::string name, std::string tag_name) {
    std::stringstream ss;
    
    if (tag_name == "") {
        ss << name << ":" << "default";
    } else {
        ss << name << ":" << tag_name;
    }

    return ss.str();
} 

template <class T>
std::shared_ptr<Metric<T>> storage::Collection::create_metric(std::string name, std::string tag_name) {
    
    std::string mertic_name = this->get_metric_name(name);
    std::string metric_uuid = UUID4::generate()();

    return NULL;
}

template std::shared_ptr<Metric<IntegerMetric>> storage::Collection::create_metric<IntegerMetric>(std::string name, std::string tag_name);

bool storage::Collection::delete_metric(std::string name, std::string tag_name) {
    return false;
}

// For whole collection deleting
bool storage::Collection::autoremove() {
    
}
// Metric<DataType>* storage::Collection::get_metric(std::string name, std::string tag_name) {
    
// }