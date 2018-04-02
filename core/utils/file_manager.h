#pragma once

#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
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

        void wtire_data(T &data) {
            if (ofs->is_open()) {
                this->_write_data(data, ofs);

                ofs->close();
            } else {
                ofs->open(this->filename, std::ios::binary | std::ios::app);
                this->_write_data(data, ofs);
                
                ofs->close();
            } 

        }

        T* read_data() {
            T *data = new T();

            if (ifs->is_open()) {
                boost::archive::binary_iarchive ia(*ifs);
                ia >> *data;

                ifs->close();
            } else {
                ifs->open(this->filename, std::ios::binary);

                boost::archive::binary_iarchive ia(*ifs);
                ia >> *data;

                ifs->close();
            }

            return data;
        }

        std::vector<T>* read_all_data() {
            std::vector<T> *data = new std::vector<T>();

            if (ifs->is_open()) {

            } else {
                ifs->open(this->filename, std::ios::binary);

                while (ifs->peek() != -1) {
                    T temp;
                    boost::archive::binary_iarchive ia(*ifs);
                    ia >> temp;
                    
                    data->push_back(temp);
                }
            }

            return data;
        }

};