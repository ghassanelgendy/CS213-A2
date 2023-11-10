#include "Counter.h"


Counter::Counter() :currentAddress(0)
{
}
Counter::Counter(int startIn) :currentAddress(startIn)
{
}

void Counter::setCounterAddress(int curAddressIn)
{
	currentAddress = curAddressIn; 
}

string Counter::getCounterAddress()
{
	return to_string(currentAddress);
}

void Counter::incrementCounter(Counter x)
{
	x.currentAddress += 2;
}
