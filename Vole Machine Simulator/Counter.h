#pragma once
#include <string>
using namespace std;
class Counter {
    string currentAddress;
public:
    Counter();

    Counter(string startIn);

    void setCounterAddress(string curAddressIn);

    string getCounterAddress();

    void incrementCounter();

};

