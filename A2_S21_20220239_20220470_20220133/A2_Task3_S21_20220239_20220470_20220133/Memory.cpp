
#include "Memory.h"

Memory::Memory() = default;


Memory::Memory(string Address , string Value ) {
        value = Value;
        address = Address;
}

void Memory::setValue(string Value) {
    value = Value;
}


string Memory::getValue() {
    return value;
}

string Memory::getAddress() {
    return address;
}

void Memory::clearMemory() {
    value = "00";

}

void Memory::setAddress(string Address) {
    address = Address;
}



