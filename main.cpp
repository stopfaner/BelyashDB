
#include <iostream>
#include "core/server/server.cpp"
#include "core/storage/collection/collection_manager.h"
#include "core/utils/file_manager.h"
// #include <vector>
#include "core/utils/logwrapper.h"


int main(int argc , char *argv[])  
{  

    storage::CollectionManager *collection_manager = new storage::CollectionManager();
    collection_manager->create_collection("collection3");

    //  server::Server* server = new server::Server(10);
    //  server->start_accepting();

	return 0;
}  
