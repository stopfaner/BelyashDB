#pragma once

#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <cstring> 
#include <iostream>
#include "../utils/logwrapper.h"


namespace storage {

    class CollectionMetadata {

        private:
            friend class boost::serialization::access;
            
            char collection_name[32];

            char filename[40];

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

