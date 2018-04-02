#pragma once

#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include "../storage/collection/collection_metadata.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
#include <string.h>

template <class T>
class FileManager {

    private:

        char *filename;

        std::ofstream *ofs = new std::ofstream();

        std::ifstream *ifs = new std::ifstream();

        void _write_data(T &data, std::ofstream *ofs) {
            boost::archive::binary_oarchive oa(*ofs);
            oa << data; 
        }

    public:
        FileManager(const char *filename){
            this->filename = new char(sizeof(filename));
            strcpy(this->filename, filename);
        }

        void wtire_data(T &data); 

        T* read_data();

        bool read_all_data(std::vector<T> &data);

};