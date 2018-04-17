#pragma once

#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <cstring> 
#include <iostream>
#include "../../utils/logwrapper.h"

#define MAX_METRIC_NAME_SIZE 32
#define MAX_TAG_NAME_SIZE 32
#define MAX_FILENAME_SIZE 40

namespace storage {
 
    class MetricMetadata {
        
        private:
            friend class boost::serialization::access;

            char        metric_name[MAX_METRIC_NAME_SIZE];
            char        tag_name[MAX_TAG_NAME_SIZE];
            // Filename of metric is uuid4 hash in str
            char        filename[MAX_FILENAME_SIZE];

            template<class Archive>
            void serialize(Archive & ar, const unsigned int version) {
                ar & metric_name;
                ar & tag_name;
                ar & filename;
            }
        
        public:

            MetricMetadata();
            MetricMetadata(char *metric_name, char *filename, char *tag_name=0);

            // Overloading of == operator for further metric comparing
            bool        operator==(const MetricMetadata &other) const;

            // Getters 
            char*       get_metric_name() const;
            char*       get_filename() const;
            char*       get_tag_name() const;

    };

}