#include "collection_manager.h"

storage::CollectionManager::CollectionManager() {
    this->collections_metadata = new std::map<std::string, CollectionMetadata>();
    this->metadata_manager = new FileManager<CollectionMetadata>("collection.meta");
    
    logger = Logger::getLogger();

    this->_load_collections_metadata();
}

void storage::CollectionManager::_load_collections_metadata() {
    std::vector<CollectionMetadata> vector;
    bool is_success = this->metadata_manager->read_all_data(vector);

    if (is_success) {
        logger->info("Collections metadata was successfully loaded.");
    } else {
        logger->warn("Collections metadata file is empty.");
    }

    for (const CollectionMetadata &metadata: vector) {
        this->collections_metadata->insert(std::make_pair(metadata.get_collection_name(), metadata));
    }
}

response::Collection storage::CollectionManager::create_collection(char *collection_name) {
                
    // Check if such exists in map already
    if (collections_metadata->find(collection_name) == collections_metadata->end()) {
        
        UUID4 uuid = UUID4::generate();
        CollectionMetadata *metadata = new CollectionMetadata(collection_name, uuid());

        this->metadata_manager->wtire_data(*metadata);

        // Creating new collection file
        std::ofstream{
            metadata->get_filename()
        };

        return response::COLLECTION_CREATED;
    } else {
        logger->warn("Such collection already exists.");

        return response::COLLECTION_EXISTS;
    }
}