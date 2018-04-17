#include "file_manager.h"

// template <class T>
// FileManager<T>::FileManager(const char *filename)

template <class T>
void FileManager<T>::write_data(const T &data) {

    if (!ofs->is_open())
        ofs->open(this->filename, std::ios::binary | std::ios::app);

    this->_write_data(data, ofs);

    ofs->close();
}
template <class T>
T* FileManager<T>::read_data() {
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

template <class T>
bool FileManager<T>::read_all_data(std::vector<T> &data) {
    if (!ifs->is_open()) 
        ifs->open(this->filename, std::ios::binary);
    
    ifs->seekg(0);

    while (ifs->peek() != -1) {
        T temp;
        boost::archive::binary_iarchive ia(*ifs);
        ia >> temp;
        
        data.push_back(temp);
    }

    if (data.size() > 0)
        return true;

    return false;
}

template <class T>
bool FileManager<T>::delete_data(const T &data) {

    std::vector<T> data_vector;

    if(!ifs->is_open()) 
        ifs->open(this->filename, std::ios::binary);

    ifs->seekg(0);

    bool is_found = false;
    while (ifs->peek() != -1) {
        T temp;
        boost::archive::binary_iarchive ia(*ifs);
        ia >> temp;

        if (temp == data) {
            is_found = true;
            continue;
        }
        
        data_vector.push_back(temp);
    }

    if (is_found) {
        std::stringstream str;
        str << this->filename;
        str << ".temp";

        ofs->open(str.str(), std::ios::binary | std::ios::app);

        for (const T &t: data_vector) {
            this->_write_data(t, ofs);
        }
        ofs->close();

        std::remove(this->filename.c_str());
        std::rename(str.str().c_str(), this->filename.c_str());

        return true;
    } else {
        return false;
    }
    data_vector.clear();

    return false;
}

template class FileManager<storage::CollectionMetadata>;
template class FileManager<storage::MetricMetadata>;
