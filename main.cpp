
#include <iostream>
#include "core/storage/collection/collection.h"
#include "core/server/server.cpp"
#include "core/storage/collection/collection_manager.h"
#include "core/storage/metric/datatype/int_metric.h"
#include "core/utils/file_manager.h"

#define LOG(x) std::cout << x << std::endl;

using namespace storage;

int main(int argc , char *argv[])  
{   
    // MetricManager *manager = MetricManager::get_manager();
    // storage::Collection *collection = new storage::Collection("test_collection", "test_uuid");
    
    std::shared_ptr<storage::CollectionManager> manager = storage::CollectionManager::get_manager();
    // manager->create_collection("university");

    // std::shared_ptr<FileManager<MetricMetadata>> manager = std::make_shared<FileManager<MetricMetadata>>("d034ec61-1090-4e59-a8ff-ceb08aa5314d");
    // std::shared_ptr<FileManager<CollectionMetadata>> manager = std::make_shared<FileManager<CollectionMetadata>>("collection.meta");
    
    
    // MetricMetadata *metadata = new MetricMetadata("metric1", "metric1_file", "tag");
    // manager->write_data(*metadata);


    // std::shared_ptr<Collection> collection = manager->get_collection("testcol");
    // std::shared_ptr<Metric<IntegerMetric>> test = collection->create_metric<IntegerMetric>("test");
    
    // server::Server* server = new server::Server(10);
    // server->start_accepting();

	return 0;
}  
