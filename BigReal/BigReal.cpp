// File: BigReal.cpp
// Purpose: Implementation file for BigReal Class (A user-defined data type that can store unlimited count of characters (numbers) and do operations on them)
// Authors: Ghassan Elgendy - Rawan Ehab - Jana Ramadan
// IDs:	       20220239     -  20220133  -   20220470
// Section: S21
// TA: Rana Abdelkader
// Date: 30 Oct 2023
#include <iostream>
#include <regex>
#include <string>
#include "BigReal.h"

BigReal::BigReal() : integer(""), fraction("")
{
}

BigReal::BigReal(const string& real)
{
	if (regex_match(real, regex("[+-]?\\d*.?\\d+"))) {
		if ((real.find('.') == string::npos)) isDot = false;
		if (real[0] == '-' || real[0] == '+') {
			if (real[0] == '-') sign = '-';
			integer = real.substr(1, real.find('.') - 1);
			if (isDot) fraction = real.substr(integer.size() + 2);
		}
		else {
			integer = real.substr(0, real.find('.'));
			if (isDot) fraction = real.substr(integer.size() + 1);
		}
		if (!isDot && sign == '-') { 
			integer = '-' + integer;
		}

	}
	else {
		integer = '0';
		fraction = '0';
	}
}

BigReal BigReal::operator+( BigReal& otherBigReal){
    BigReal value;
	
    if (integer.size() > otherBigReal.integer.size()){
        otherBigReal.integer.insert(0, integer.size() - otherBigReal.integer.size(), '0');
    }
    else {
        integer.insert(0, otherBigReal.integer.size()-integer.size() , '0');
    }
    if (fraction.size() > otherBigReal.fraction.size()){
        otherBigReal.fraction.insert(otherBigReal.fraction.size(), fraction.size() - otherBigReal.fraction.size(), '0');
    }
    else {
        fraction.insert(fraction.size(), otherBigReal.fraction.size() - fraction.size()  , '0');
    }
	int carry = 0;
    for (int i = fraction.size()-1; i >= 0 ; --i) {
        int res ;
		res = (int)((fraction[i])-'0') + (int)((otherBigReal.fraction[i])-'0') + carry;
        carry=0;																			                                       
        if (res > 9){                                                 
            carry++;
            res %= 10;
        }
		value.fraction.insert(0,1,char(res)+'0');
    }
	for (int i = integer.size() - 1; i >= 0; --i) {
		int res;
		res = (int)((integer[i]) - '0') + (int)((otherBigReal.integer[i]) - '0') + carry;
		carry = 0;
		if (res > 9) {
			carry++;
			res %= 10;
		}
		value.integer.insert(0, 1, char(res) + '0');
	}

	return value;
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
	else output << BigR.integer;
	return output;
}
