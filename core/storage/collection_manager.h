#pragma once
#include <map>
#include <fstream>
#include <cstring>
#include "response.h"
#include "../utils/logwrapper.h"
#include "collection_metadata.h"
#include "../utils/file_manager.h"
#include "../server/uuid4.h"

namespace storage {

    class CollectionManager {

        private:

            std::map<std::string, CollectionMetadata> *collections_metadata;

            FileManager<CollectionMetadata> *metadata_manager;
            
            // Loading collections metadata from storage file
            void _load_collections_metadata();

        public:

            CollectionManager();

            response::Collection create_collection(char *collection_name);
    };
}