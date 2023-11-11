
#ifndef CS213_A2_MEMORY_H
#define CS213_A2_MEMORY_H
#include "register.h"


class Memory {
    string value;
    string address;
public:
    Memory();
    Memory(string Address , string Value ) ;
   void setValue(string Value);
   string getValue();
   void setAddress(string Address);
   string getAddress();
   void clearMemory();



};


#endif //CS213_A2_MEMORY_H
