#include "collection_metadata.h"

const char *CollectionMetadata::DEFAULT_FILENAME = "collections.meta";

CollectionMetadata::CollectionMetadata() {

}

CollectionMetadata::CollectionMetadata(char *collection_name, char *file_name) {
    strcpy(this->collection_name, collection_name);
    strcpy(this->filename, file_name);
}

char* CollectionMetadata::get_collection_name() const {
    char *collection_name = new char[32];

    strcpy(collection_name, this->collection_name);

    return collection_name;
}

char* CollectionMetadata::get_filename() const {
    char *filename = new char[sizeof(this->filename) + 1];

    strcpy(filename, this->filename);

    return filename;
}