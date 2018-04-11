#include "collection_manager.h"

storage::CollectionManager::CollectionManager() {
    this->collections_metadata = new std::map<std::string, CollectionMetadata>();
    this->metadata_manager = new FileManager<CollectionMetadata>("collection.meta");
    this->collections = std::make_shared<std::map<std::string, Collection>>();
    logger = Logger::getLogger();

    this->_load_collections_metadata();
}

std::shared_ptr<storage::CollectionManager> storage::CollectionManager::get_manager() {

    if (manager.get() == 0) {
        manager = std::make_shared<CollectionManager>();
    }

    return manager;
}

std::shared_ptr<storage::CollectionManager> storage::CollectionManager::manager = nullptr;

void storage::CollectionManager::_load_collections_metadata() {
    std::vector<CollectionMetadata> vector;
    bool is_success = this->metadata_manager->read_all_data(vector);

    if (is_success) {
        logger->info("Collections metadata was successfully loaded.");
    } else {
        logger->warn("Collections metadata file is empty.");
    }

    if (is_success) {
        for (const CollectionMetadata &metadata: vector) {
            std::cout << "name: " << metadata.get_collection_name() << " uuid: " << metadata.get_filename() << std::endl;
            this->collections_metadata->insert(std::make_pair(metadata.get_collection_name(), metadata));
        }

        // Loading got metadata into collections map
        this->_load_collections_map();
    }
}

void storage::CollectionManager::_load_collections_map() {

    for (std::map<std::string, CollectionMetadata>::iterator iter = collections_metadata->begin(); iter != collections_metadata->end(); ++iter) {
        std::string collection_name = iter->first;
        CollectionMetadata metadata = iter->second;
        Collection *collection = new Collection(collection_name, metadata.get_filename());

        // collections->insert(std::make_pair());
    }
}

bool storage::CollectionManager::create_collection(char *collection_name) {
                
    // Check if such exists in map already
    if (collections_metadata->find(collection_name) == collections_metadata->end()) {
        
        UUID4 uuid = UUID4::generate();
        CollectionMetadata *metadata = new CollectionMetadata(collection_name, uuid());

        this->metadata_manager->write_data(*metadata);

        // Creating new collection file
        std::ofstream{
            metadata->get_filename()
        };

        return true;
    } else {
        logger->warn("Such collection already exists.");

        return false;
    }
}

std::shared_ptr<std::map<std::string, storage::Collection>> storage::CollectionManager::get_collections() const {
    return this->collections;
}

std::shared_ptr<storage::Collection> storage::CollectionManager::get_collection(std::string name) const {
    std::map<std::string, Collection>::const_iterator pos = collections->find(name);

    if (pos == collections->end()) {
        std::cout << "Not found" << std::endl;
    } else {
        return std::make_shared<storage::Collection>(pos->second);
    }
}