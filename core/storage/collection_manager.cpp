#include "collection_manager.h"

storage::CollectionManager::CollectionManager() {
    this->collections_metadata = NULL;
    this->metadata_manager = new FileManager<CollectionMetadata>("collection.meta");
}

void storage::CollectionManager::_load_collections_metadata() {
    this->collections_metadata = this->metadata_manager->read_all_data();

    if (collections_metadata != NULL) {
        std::cout << "Collections metadata was successfully loaded." << std::endl;
    } else {
        std::cout << "Collections metadata file is empty" << std::endl;
    }

    // for test
    for (const auto &data: *this->collections_metadata) {
        std::cout << data.get_collection_name() << ": " << data.get_filename() <<std::endl;
    }
}