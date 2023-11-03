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

BigReal::BigReal() : integer(""), fraction(""), isDot(true), sign('+'){ }

BigReal::BigReal(const string& realString) : isDot(true), sign('+')
{
	*this = realString;
}

bool BigReal::isValidReal(const string& realString)
{
	if (regex_match(realString, regex("[+-]?\\d*\\.?\\d*"))) return true; //using regex to validate the number
	else {
		cout << "Invalid input\nError code 900";
		exit(900);
	}
}

BigReal& BigReal::operator =(const string& realString) {
	if (isValidReal(realString)) {
		string temp;
		temp = realString;
		if ((realString.find('.') == string::npos)) isDot = false;
		if (realString[0] == '-' || realString[0] == '+') {
			temp = realString.substr(1, realString.size() - 1); //if there is a sign we make a temporary variable without it
			if (realString[0] == '-') sign = '-'; //saves the sign
		}
		integer = temp.substr(0, temp.find('.')); //initialezes the integer part starting from the first digit to the dot
		if (isDot) fraction = temp.substr(integer.size() + 1, temp.size() - 1); //initialize the fraction part from after the dot
		this->removeLead();
	}
	return *this;
}

ostream& operator<<(ostream& output, const BigReal& BigR) //overloading the output operator
{
	if (BigR.sign == '-') output << BigR.sign;
	if (BigR.isDot) output << BigR.integer << '.' << BigR.fraction;  //puts the whole number together
	else output << BigR.integer;
	return output;
}
BigReal BigReal::removeLead()
{
	while (integer[0] == '0' && integer.size() >= 1) //delete leading zeros
	{
		integer.erase(0, 1);
	}
	while (!fraction.empty() && fraction[fraction.size() - 1] == '0') //delete leading zeros
	{
		fraction.erase(fraction.size() - 1, 1);
	}
	if (integer.empty()) integer = '0'; //default value is zero
	if (fraction.empty()) fraction = '0';
	return *this;
}
bool BigReal::operator>(BigReal& otherBigReal)
{
	if (this->sign == '+' && otherBigReal.sign=='-') return true;       //if first is positive and second is negative
	if (this->sign == '-' && otherBigReal.sign == '+') return false;    //if first is negative and second is positive
	if (this->sign == '-' && otherBigReal.sign == '-') {      //if both are negative , we swap them to check
		swap(*this, otherBigReal);
	}
	if ((this->removeLead().integer).size() >
		(otherBigReal.removeLead().integer.size())) { //compares integer sizes
		return true;
	}
	for (size_t i = (this->integer.size()) - 1; i > 0; i--)
	{
		if (this->integer[i]> otherBigReal.integer[i])
			return true;
	}
	if ((this->removeLead().fraction).size() >
		(otherBigReal.removeLead().fraction.size())) { //compares integer sizes
		return true;
	}
	for (size_t i = 0; i < otherBigReal.fraction.size()-1; i++)    //compares fraction if the integer part is the samae in both
	{
		if ((unsigned short)this->fraction[i] > (unsigned short)otherBigReal.fraction[i])
		return true;
	}
	return false;
}

bool BigReal::operator<(BigReal& otherBigReal)
{
	return (!(*this > otherBigReal) && !(*this == otherBigReal)); //if not greater than and not equal then it's definitely less than
}

bool BigReal::operator==(BigReal& otherBigReal)
{
	return (this->removeLead().integer == otherBigReal.removeLead().integer &&    //checks if integer part is equal
			this->removeLead().fraction == (otherBigReal.removeLead().fraction) &&      //checks if fraction part is equal
			this->sign == otherBigReal.sign);            //checks if signs are equal
}
void BigReal::Pad(BigReal& a, BigReal& b) //makes both BigReals have the same size by adding zeros
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

istream& operator>>(istream& input, BigReal& bigR) //overloading the input operator
{
	string input_str;
	getline(input, input_str);
	bigR = BigReal(input_str);
	return input;
}

//BigReal BigReal::operator+(BigReal& otherBigReal){
//    BigReal value;
//	Pad(*this, otherBigReal);
//	int carry = 0;
//    for (int i = fraction.size()-1; i >= 0 ; --i) {
//        int res ;
//		res = (int)((fraction[i])-'0') + (int)((otherBigReal.fraction[i])-'0') + carry;
//        carry=0;							                                       
//        if (res > 9){ //condition to  increment the carry and take only the last digit if the result is big than 9                                                 
//            carry++;
//            res %= 10;
//        }
//		value.fraction.insert(0,1,char(res)+'0');
//    }
//	for (int i = integer.size() - 1; i >= 0; --i) {
//		int res;
//		res = (int)((integer[i]) - '0') + (int)((otherBigReal.integer[i]) - '0') + carry;
//		carry = 0;
//		if (res > 9) {
//			carry++;
//			res %= 10;
//		}
//		value.integer.insert(0, 1, char(res) + '0');
//	}
//	return value;
//}
//BigReal BigReal::operator-(BigReal& otherBigReal) {
//	BigReal value;
//	Pad(*this, otherBigReal);
//	int borrow = 0;
//
//	if (otherBigReal > *this) {
//		value = otherBigReal;
//		value.sign = '-';
//		return value;
//	}
//
//	if (this->sign == otherBigReal.sign) {
//		if (this->sign == '+') { // both positive
//			if (*this > otherBigReal || *this == otherBigReal) { // first is bigger or equal to
//				for (int i = fraction.size() - 1; i >= 0; --i) {
//					int res = (fraction[i] - '0') - (otherBigReal.fraction[i] - '0') - borrow;
//					borrow = 0;
//					if (res < 0) {
//						borrow++;
//						res += 10;
//					}
//					value.fraction.insert(0, 1, res + '0');
//				}
//
//				borrow = 0;
//				for (int i = integer.size() - 1; i >= 0; --i) {
//					int res = (integer[i] - '0') - (otherBigReal.integer[i] - '0') - borrow;
//					borrow = 0;
//					if (res < 0) {
//						borrow++;
//						res += 10;
//					}
//					value.integer.insert(0, 1, res + '0');
//				}
//			}
//			else { // both positive but other is bigger
//				value = otherBigReal - *this; // Swap and negate result
//				value.sign = '-';
//			}
//		}
//		else { // both negative
//			this->sign = '+';
//			otherBigReal.sign = '+';
//			value = otherBigReal - *this;
//		}
//	}
//	else {
//		 If different signs, convert subtraction to addition
//		if (this->sign == '+') {
//			otherBigReal.sign = '+';
//			value = *this + otherBigReal;
//		}
//		else {
//			this->sign = '+';
//			value = *this + otherBigReal;
//			value.sign = '-';
//		}
//	}
//
//	return value;
//}
//



