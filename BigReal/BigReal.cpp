// BigReal.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include "BigReal.h"

BigReal::BigReal()
{
}

BigReal::BigReal(string real)
{
}

BigReal BigReal::operator+(BigReal& otherBigReal)
{
	return BigReal();
}

BigReal BigReal::operator-(BigReal& otherBigReal)
{
	return BigReal();
}

BigReal BigReal::operator==(BigReal& otherBigReal)
{
	return BigReal();
}

BigReal BigReal::operator>(BigReal& otherBigReal)
{
	return BigReal();
}

BigReal BigReal::operator<(BigReal& otherBigReal)
{
	return BigReal();
}

void BigReal::print()
{
	cout << sign << integer << dot << fraction;
}
