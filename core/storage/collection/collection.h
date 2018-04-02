#pragma once
#include "../../utils/uuid4.h"
#include "../../utils/logwrapper.h"

#define MAX_COLLECTION_NAME_SIZE 32

namespace collection {
    
    class Collection {
        
        private:

            char collection_name[MAX_COLLECTION_NAME_SIZE];

            UUID4 collection_uuid;

    }; 
}