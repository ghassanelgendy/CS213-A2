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
#include <stdlib.h>
#include "BigReal.h"

BigReal::BigReal() : integer(""), fraction(""), isDot(true), sign('+')
{

}
bool BigReal::isValidReal(const string& realString)
{
	if (regex_match(realString, regex("[+-]?\\d*\\.?\\d*"))) return true; //using regex to validate the number
	else {
		cout << "Invalid input\nError code 900";
		exit(900);
	}
}

BigReal BigReal::removeLead()
{
	while (integer[0] == '0' && integer[1] == '0') //delete leading zeros
	{
		integer.erase(0, 1);
	}
	while (!fraction.empty() && fraction[fraction.size() - 1] == '0' && fraction[fraction.size() - 2] != '0') //delete leading zeros
	{
		fraction.erase(fraction.size() - 1, 1);
	}
	return *this;
}

BigReal::BigReal(const string& realString): isDot(true), sign('+')
{
	*this = realString;
}

BigReal BigReal::operator+(BigReal& otherBigReal){
    BigReal value;
	Pad(*this, otherBigReal);
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

BigReal BigReal::operator-(BigReal& other)
{
	BigReal value;
	Pad(*this, other);

	string intComp;
	string fracComp;
	for (char digit : other.integer) {
		intComp += '9' - (digit - '0') + '0';
	}
	

	return value;
}

bool BigReal::operator==(BigReal& otherBigReal)
{
	 
	return (this->removeLead().integer == otherBigReal.removeLead().integer &&
			this->removeLead().fraction == (otherBigReal.removeLead().fraction) &&
			this->sign == otherBigReal.sign);
}

bool BigReal::operator>(BigReal& otherBigReal)
{
	bool yes{ false };
	for (size_t i = 0; i < 6; i++)
	{

	}//789456123 - 48576761
	if ((unsigned short)(this->removeLead().integer).size() >
		(unsigned short)(otherBigReal.removeLead().integer.size())) {
		yes = true;
		return yes;
	}
	for (size_t i = (otherBigReal.integer.size()) - 1; i >= 0; i--)
	{
		if ((unsigned short)this->integer[i] > (unsigned short)otherBigReal.integer[i])
		yes = true;
		break;
	}
	if (!yes) {
		for (size_t i = 0; i < otherBigReal.fraction.size()-1; i++)
		{
			if ((unsigned short)this->fraction[i] > (unsigned short)otherBigReal.fraction[i]) 
				yes = true;
			break;
		}
	}
	return yes;
}

bool BigReal::operator<(BigReal& otherBigReal)
{
	return (!(*this > otherBigReal) && !(*this == otherBigReal));
}



BigReal& BigReal::operator =(const string& realString) {
	if (isValidReal(realString)) {
		string temp;
		temp = realString;
		if ((realString.find('.') == string::npos)) isDot = false;
		if (realString[0] == '-' || realString[0] == '+') {
			temp = realString.substr(1, realString.size() - 1);
			if (realString[0] == '-') sign = '-';
		}
		integer = temp.substr(0, temp.find('.'));
		if (isDot) fraction = temp.substr(integer.size() + 1, temp.size() - 1);
		//we now have a good lookin int and frac
		while (integer[0] == '0' && integer.size() >= 1) //delete leading zeros
		{
			integer.erase(0, 1);
		}
		while (!fraction.empty() && fraction[fraction.size() - 1] == '0') //delete leading zeros
		{
			fraction.erase(fraction.size() - 1, 1);
		}
		if (integer.empty()) integer = '0';
		if (fraction.empty()) fraction= '0';

	}
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
	if (BigR.sign == '-') output << BigR.sign;
	if (BigR.isDot) output << BigR.integer << '.' << BigR.fraction;
	else output << BigR.integer;
	return output;
}
void BigReal::Pad(BigReal& a, BigReal& b)
{
	if (a.integer.size() > b.integer.size()) {
		b.integer.insert(0, a.integer.size() - b.integer.size(), '0');
	}
	else {
		a.integer.insert(0, b.integer.size() - a.integer.size(), '0');
	}
	if (a.fraction.size() > b.fraction.size()) {
		b.fraction.insert(b.fraction.size(), a.fraction.size() - b.fraction.size(), '0');
	}
	else {
		a.fraction.insert(a.fraction.size(), b.fraction.size() - a.fraction.size(), '0');
	}
}
