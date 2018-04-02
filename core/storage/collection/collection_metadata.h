#pragma once

#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <cstring> 
#include <iostream>
#include "../../utils/logwrapper.h"

#define MAX_COLLECTION_NAME_SIZE 32
#define MAX_FILENAME_SIZE 40

namespace storage {

    class CollectionMetadata {

        private:
            friend class boost::serialization::access;
            
            // Name of collection with MAX_SIZE 32
            char            collection_name[MAX_COLLECTION_NAME_SIZE];
            // Filename of collection is uuid4 hash in str
            char            filename[MAX_FILENAME_SIZE];

            template<class Archive>
            void serialize(Archive & ar, const unsigned int version) {
                ar & collection_name;
                ar & filename;
            }

        public:

            // Default filename of colllections metadata 
            const static char *DEFAULT_FILENAME;

            CollectionMetadata();

            CollectionMetadata(char *collection_name, char *file_name);

            char* get_collection_name() const;

            char* get_filename() const;
    };

}

