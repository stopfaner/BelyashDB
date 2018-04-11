#pragma once 

#include <map>
#include <iostream>
#include <vector>
#include "metric.h"
#include "metric_metadata.h"
// #include "../../utils/file_manager.h"
#include "../../utils/uuid4.h"
#include <memory>
#include <string>

namespace storage {

    // This class manages metrics inside a collection
    class MetricManager {
        
        private:

            static std::shared_ptr<MetricManager> manager;

            // FileManager<MetricMetadata> *metric_metadata;

        protected:
            explicit MetricManager();

            MetricManager(const MetricManager &) = delete;
            const MetricManager &operator= (const MetricManager &) = delete;

        public:

            ~MetricManager();

            static std::shared_ptr<MetricManager> get_manager();

            // Common actions with metric
            bool create_metric(const UUID4 &collection_uuid, std::string metric_name, std::string tag_name = 0);
            bool delete_metric(const UUID4 &collection_uuid, std::string metric_name, std::string tag_name = 0);

            bool load_metrics(std::string collection_name, std::vector<std::shared_ptr<Metric<DataType>>> &metrics);
            
    };

}