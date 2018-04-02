
#include <iostream>
#include "core/server/server.cpp"
#include "core/storage/collection_manager.h"
#include "core/utils/file_manager.h"
#include <vector>

// class gps_position
// {
// private:
//     friend class boost::serialization::access;
//     template<class Archive>
//     void serialize(Archive & ar, const unsigned int version)
//     {
//         ar & degrees;
//         ar & minutes;
//         ar & seconds;
//     }
//     int degrees;
//     int minutes;
//     float seconds;

// public:
//     gps_position(){};
//     gps_position(int d, int m, float s) :
//     degrees(d), minutes(m), seconds(s)
//     {}

//     int get_d() const {
//         return this->degrees;
//     }
// };

int main(int argc , char *argv[])  
{  

    storage::CollectionManager *collection_manager = new storage::CollectionManager();
    collection_manager->create_collection("test");
    collection_manager->create_collection("test2");
    collection_manager->create_collection("test3");
    collection_manager->create_collection("test2");
    // collection_manager->create_collection("test3");
    CollectionMetadata *metadata = new CollectionMetadata("collection3", "test_collection_6");

    FileManager<CollectionMetadata> *manager = new FileManager<CollectionMetadata>("test.dat");
    // manager->wtire_data(*metadata);

    // std::vector<CollectionMetadata> *data = manager->read_all_data();
    // for (const auto &data: *data) {
    //     std::cout << data.get_filename() << std::endl;
    // }

    //  server::Server* server = new server::Server(10);
    //  server->start_accepting();

	return 0;
}  
