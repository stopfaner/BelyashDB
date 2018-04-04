#include "file_manager.h"

// template <class T>
// FileManager<T>::FileManager(const char *filename)

template <class T>
void FileManager<T>::wtire_data(T &data) {
    if (ofs->is_open()) {
        this->_write_data(data, ofs);

        ofs->close();
    } else {
        ofs->open(this->filename, std::ios::binary | std::ios::app);
        this->_write_data(data, ofs);
        
        ofs->close();
    } 
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

template class FileManager<storage::CollectionMetadata>;
template class FileManager<storage::MetricMetadata>;
