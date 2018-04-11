#pragma once

#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include "../storage/collection/collection_metadata.h"
#include "../storage/metric/metric_metadata.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
#include <string.h>
#include <memory>

template <class T>
class FileManager {

    private:

        std::string filename;

        std::ofstream *ofs;

        std::ifstream *ifs;

        void _write_data(T &data, std::ofstream *ofs) {
            boost::archive::binary_oarchive oa(*ofs);
            oa << data; 
        }

    public:
        FileManager(const std::string &filename): filename(filename) {
            this->ofs = new std::ofstream();
            this->ifs = new std::ifstream();
        }

        void write_data(T &data);

        T* read_data();

        bool read_all_data(std::vector<T> &data);

};