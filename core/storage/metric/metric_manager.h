#pragma once 

#include <map>
#include <iostream>
#include "metric_metadata.h"
// #include "../../utils/file_manager.h"
#include "../../utils/uuid4.h"
#include <string>

namespace storage {

    // This class manages metrics inside a collection
    class MetricManager {
        
        private:

            static MetricManager *manager;

            // FileManager<MetricMetadata> *metric_metadata;

            MetricManager();

        public:

            ~MetricManager();

            static MetricManager* get_manager();

            // Common actions with metric
            bool create_metric(const UUID4 &collection_uuid, std::string metric_name, std::string tag_name = 0);
            bool delete_metric(const UUID4 &collection_uuid, std::string metric_name, std::string tag_name = 0);
            
    };

}