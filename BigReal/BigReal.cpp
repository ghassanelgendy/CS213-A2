// File: BigReal.cpp
// Purpose: Implementation file for BigReal Class (A user-defined data type that can store unlimited count of characters (numbers) and do operations on them)
// Authors: Ghassan Elgendy - Rawan Ehab - Jana Ramadan
// IDs:	       20220239     -  20220133  -   20220270
// Section: S21
// TA: Rana Abdelkader
// Date: 30 Oct 2023
#include <iostream>
#include <regex>
#include <string>
#include "BigReal.h"

BigReal::BigReal() : integer("0"), fraction("0")
{
}

BigReal::BigReal(const string& real)
{
	if (regex_match(real, regex("[+-]?\\d*.?\\d+"))) {
		string temp;
		temp = real;
		if (!(real.find('.') == string::npos)) isDot = true;
		if (real[0] == '-' || real[0] == '+') {
			temp = real.substr(1, real.size() - 1);
			if(real[0] == '-') sign = '-';
		}
		integer = temp.substr(0, temp.find('.'));
		if (isDot) fraction = temp.substr(integer.size() + 1, temp.size() - 1);
	}
	else {
		integer = '0';
		fraction = '0';
	}
}

BigReal BigReal::operator+(const BigReal& otherBigReal)
{
	return BigReal();
}

BigReal BigReal::operator-(const BigReal& otherBigReal)
{
	return BigReal();
}

BigReal BigReal::operator==(const BigReal& otherBigReal)
{
	return BigReal();
}

BigReal BigReal::operator>(const BigReal& otherBigReal)
{
	return BigReal();
}

BigReal BigReal::operator<(const BigReal& otherBigReal)
{
	return BigReal();
}

BigReal& BigReal::operator =(const string& BigR) {
	BigReal temp(BigR);
	integer = move(temp.integer);
	fraction = move(temp.fraction);
	isDot = move(temp.isDot);
	sign = move(temp.sign);
	return *this;
}


istream& operator>>(istream& input, BigReal& bigR)
{
	string input_str;
	input >> input_str;
	bigR = BigReal(input_str);
	return input;  
}

ostream& operator<<(ostream& output, const BigReal& BigR)
{
	if (BigR.isDot) output << BigR.sign << BigR.integer << '.' << BigR.fraction;
	else output << BigR.sign << BigR.integer;
	return output;
}
