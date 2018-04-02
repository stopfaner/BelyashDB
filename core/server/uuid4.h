#pragma once

#include <uuid/uuid.h>

class UUID4 {

    public:
        uuid_t uuid;

        UUID4();

        UUID4(const UUID4 &other);
        UUID4(const uuid_t other_uuid);

        void generateInplace();

        static UUID4 generate();

        bool operator<(const UUID4 &other);
        bool operator==(const UUID4 &other);

        char* operator()();

};