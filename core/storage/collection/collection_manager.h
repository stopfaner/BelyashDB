#pragma once
#include <map>
#include <fstream>
#include <cstring>
#include "../response.h"
#include "../../utils/logwrapper.h"
#include "collection_metadata.h"
#include "../metric/metric_manager.h"
#include "collection.h"
#include "../../utils/file_manager.h"
#include "../../utils/uuid4.h"
#include <memory>

namespace storage {

    class CollectionManager {

        private:
            // Logger instance 
            Logger                                      *logger;

            static CollectionManager                    *manager;

            std::map<std::string, CollectionMetadata>   *collections_metadata;

            FileManager<CollectionMetadata>             *metadata_manager;
            
            std::vector<std::shared_ptr<Collection>>    collections;

            // Loading collections metadata from storage file
            void                                        _load_collections_metadata();

            CollectionManager();

        public:

            static CollectionManager* get_manager();

            // Creating new collection
            response::CollectionResponse                        create_collection(char *collection_name);
            // storage::Collection*                        get_collection(std::string collection_name);
    };
}