#pragma once

#include <string>
#include <vector>
#include <map>
#include "collection_metadata.h"
#include "../../utils/uuid4.h"
#include "../../utils/logwrapper.h"
#include "../../utils/file_manager.h"
#include "../metric/metric.h"
#include "../metric/metric_manager.h"

#define MAX_COLLECTION_NAME_SIZE 32

namespace storage {
    
    class Collection {
        
        private:
            Logger *logger;

            std::string collection_name;
            std::string collection_uuid;

            std::map<std::string, MetricMetadata>   *metric_metadata;

            std::shared_ptr<std::map<std::string, Metric<DataType>>> metrics;

            std::shared_ptr<FileManager<MetricMetadata>> file_manager;

            bool _load_metrics_metadata();
            bool _load_metrics();
            void _initialize();
            
            std::string get_metric_name(std::string name, std::string tag_name = "");

        public:

            Collection();
            Collection(std::string name, std::string uuid);
            Collection(std::string name, const CollectionMetadata &metadata);
            Collection(const Collection &collection);

            ~Collection();

            std::string get_name() const;
            std::string get_uuid() const;

            std::map<std::string, Metric<DataType>>             get_metrics() const;

            std::map<std::string, Metric<DataType>>             get_metric(std::string name) const;

            // For creating metric in collection
            template <class T>
            std::shared_ptr<Metric<T>>                          create_metric(std::string name, std::string tag_name = "");

            bool                                                delete_metric(std::string name, std::string tag_name);

            bool                                                autoremove();

            // Metric<DataType>* get_metric(std::string name, std::string tag_name);

    }; 
}