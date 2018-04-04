#pragma once

#include <string>
#include "../../utils/uuid4.h"
#include "../../utils/logwrapper.h"
#include "../metric/metric_manager.h"

#define MAX_COLLECTION_NAME_SIZE 32

namespace storage {
    
    class Collection {
        
        private:

            std::string collection_name;

            UUID4 collection_uuid;

            MetricManager   *metric_manager;
        public:

            Collection() {
                metric_manager = MetricManager::get_manager();
                collection_uuid = UUID4::generate();
            }

            bool create_metric(std::string name, std::string tag_name = 0);

    }; 
}