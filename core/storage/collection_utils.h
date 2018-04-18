#pragma once

#define CREATE_COLLECTION   "create_collection()"
#define DELETE_COLLECTION   "delete_collection()"
#define SHOW_COLLECTIONS    "show_collections()"

#define USE_COLLECTION      "use()"
#define EXIT_COLLECTION     "exit_collection()"

enum CollectionCase {
    COLLECTION_CREATED,
    COLLECTION_DELETED,
    COLLECTION_EXIST,
    COLLECTION_DOES_NOT_EXIST,
    CREATION_ERROR,
    DELETION_ERROR,
    NO_COLLECTIONS
};
