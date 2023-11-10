#pragma once
#include <string>
using namespace std;
class Counter
{
	int currentAddress;
public:
	Counter();
	Counter(int startIn);
	void setCounterAddress(int curAddressIn);
	string getCounterAddress();
	static void incrementCounter(Counter x);
};

