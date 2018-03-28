#include "uuid4.h"

UUID4::UUID4() {

}

UUID4::UUID4(const UUID4 &other) { 
    uuid_copy(uuid, other.uuid); 
}

UUID4::UUID4(const uuid_t other_uuid) { 
    uuid_copy(uuid, other_uuid); 
}

void UUID4::generateInplace() { 
    uuid_generate(uuid); 
}

UUID4 UUID4::generate() { 
    UUID4 wrapped; 
    uuid_generate(wrapped.uuid); return wrapped; 
}

bool UUID4::operator<(const UUID4 &other) { 
    return uuid_compare(uuid, other.uuid) < 0; 
}

bool UUID4::operator==(const UUID4 &other) {
    return uuid_compare(uuid, other.uuid) == 0; 
}