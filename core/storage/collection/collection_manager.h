#pragma once
#include <map>
#include <fstream>
#include <cstring>
#include "collection.h"
#include <memory>

#include "collection_metadata.h"
#include "../response.h"
#include "../../utils/logwrapper.h"
#include "../metric/metric_manager.h"
#include "../../utils/file_manager.h"
#include "../../utils/uuid4.h"
#include "../collection_utils.h"

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
            std::shared_ptr<CollectionMetadata>         _find_collection_metadata(std::string collection_name);
            std::shared_ptr<Collection>                 _find_collection(std::string collection_name);


        protected:

            CollectionManager(const CollectionManager &) = delete;
            const CollectionManager &operator=(const CollectionManager &) = delete;


        public:

            explicit CollectionManager();

            static std::shared_ptr<CollectionManager> get_manager();

            bool                        get_collections(std::vector<Collection> &vector) const;

            std::shared_ptr<Collection> get_collection(std::string name) const;

            // Creating new collection
            CollectionCase              create_collection(char *collection_name);
            CollectionCase              delete_collection(std::string collection_name);
    };
}