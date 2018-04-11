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

            static std::shared_ptr<CollectionManager>   manager;

            std::map<std::string, CollectionMetadata>   *collections_metadata;

            FileManager<CollectionMetadata>             *metadata_manager;

            std::shared_ptr<std::map<std::string, Collection>> collections;

            // Loading collections metadata from storage file
            void                                        _load_collections_metadata();
            void                                        _load_collections_map();


        protected:

            CollectionManager(const CollectionManager &) = delete;
            const CollectionManager &operator=(const CollectionManager &) = delete;


        public:

            explicit CollectionManager();

            static std::shared_ptr<CollectionManager> get_manager();

            std::shared_ptr<std::map<std::string, Collection>> get_collections() const;

            std::shared_ptr<Collection> get_collection(std::string name) const;

            // Creating new collection
            bool                        create_collection(char *collection_name);
    };
}