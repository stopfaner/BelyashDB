#include "collection_metadata.h"

const char *storage::CollectionMetadata::DEFAULT_FILENAME = "collections.meta";

storage::CollectionMetadata::CollectionMetadata() {

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