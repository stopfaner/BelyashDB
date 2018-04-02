#pragma once
#include <vector>
#include <fstream>
#include "collection_metadata.h"
#include "../utils/file_manager.h"
#include "../server/uuid4.h"

namespace storage {

    class CollectionManager {

        private:

            std::vector<CollectionMetadata> *collections_metadata;

            FileManager<CollectionMetadata> *metadata_manager;
            
            // Loading collections metadata from storage file
            void _load_collections_metadata();

        public:

            CollectionManager();

            void create_collection(char *collection_name) {

                UUID4 uuid = UUID4::generate();
                CollectionMetadata *metadata = new CollectionMetadata(collection_name, uuid());

                std::cout << metadata->get_collection_name() << ": " <<  metadata->get_filename() << std::endl;

                this->metadata_manager->wtire_data(*metadata);

                // collections_metadata->push_back(*metadata);

                // std::ofstream{
                //     metadata->get_filename()
                // };
            }
    };
}

