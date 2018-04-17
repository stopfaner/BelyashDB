#include "collection_metadata.h"

const char *storage::CollectionMetadata::DEFAULT_FILENAME = "collections.meta";

storage::CollectionMetadata::CollectionMetadata() {

}

storage::CollectionMetadata::CollectionMetadata(const CollectionMetadata &metadata) {
    strcpy(this->collection_name, metadata.get_collection_name());
    strcpy(this->filename, metadata.get_filename());
}

storage::CollectionMetadata::CollectionMetadata(char *collection_name, char *file_name) {
    strcpy(this->collection_name, collection_name);
    strcpy(this->filename, file_name);
}

char* storage::CollectionMetadata::get_collection_name() const {
    char *collection_name = new char[sizeof(this->collection_name) + 1];

    strcpy(collection_name, this->collection_name);

    return collection_name;
}

char* storage::CollectionMetadata::get_filename() const {
    char *filename = new char[sizeof(this->filename) + 1];

    strcpy(filename, this->filename);

    return filename;
}

bool storage::CollectionMetadata::operator==(const CollectionMetadata &metadata) const{
    
    if (std::strcmp(this->collection_name, metadata.get_collection_name()) != 0) {
        return false;
    }

    if (std::strcmp(this->filename, metadata.get_filename()) != 0) {
        return false;
    }

    return true;
}