
#include <iostream>
#include "core/storage/collection/collection.h"
// #include "core/storage/metric/metric_manager.h"
// #include "core/server/server.cpp"
#include "core/storage/collection/collection_manager.h"
// #include "core/utils/file_manager.h"
// #include "core/utils/logwrapper.h"
// #include "core/storage/metric/metric.h"
// #include "core/storage/metric/datatype/int_metric.h"


using namespace storage;
int main(int argc , char *argv[])  
{   
    // MetricManager *manager = MetricManager::get_manager();
    storage::Collection *collection = new storage::Collection();
    storage::CollectionManager *manager = storage::CollectionManager::get_manager();
    
    // Metric<IntegerMetric>* metric = new Metric<IntegerMetric>("test");
    // IntegerMetric *metric_data = new IntegerMetric(25);
    // metric->add_data(*metric_data);
    // metric->add_data(*metric_data);
    // // metric->add_data(*metric_data);
    // metric->print_metrics();
    // storage::CollectionManager *collection_manager = new storage::CollectionManager();
    // collection_manager->create_collection("testcol2");

    //  server::Server* server = new server::Server(10);
    //  server->start_accepting();

	return 0;
}  
