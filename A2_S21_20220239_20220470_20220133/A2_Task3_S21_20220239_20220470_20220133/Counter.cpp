// File: Counter.cpp
// Authors: Ghassan Elgendy - Rawan Ehab - Jana Ramadan
// IDs:	       20220239     -  20220133  -   20220470
// Section: S21
// TA: Rana Abdelkader
// Date: 15 Nov 2023
#include "Counter.h"
#include "Machine.h"





Counter::Counter() :currentAddress("00")
{
}
Counter::Counter(string startIn) 
{
	currentAddress = startIn;
}

void Counter::setCounterAddress(string curAddressIn)
{
	currentAddress = curAddressIn; 
}

string Counter::getCounterAddress()
{
	return currentAddress;
}

void Counter::incrementCounter()
{
	string x = Machine::toHex(Machine::toDec(currentAddress) + 2);
	if (x.size() == 1)
		currentAddress = '0' + x;
	else
		currentAddress = x;
}
