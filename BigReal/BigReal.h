// File: BigReal.h
// Purpose: Header file for BigReal Class
// Authors: Ghassan Elgendy - Rawan Ehab - Jana Ramadan
// IDs:	       20220239     -  20220133  -   20220270
// Section: S21
// TA: Rana Abdelkader
// Date: 30 Oct 2023
#include <string>

using namespace std;
#pragma once
class BigReal
{
private:
	bool isDot = false;
	char sign = '+';
	string integer;
	string fraction; 
public:
	BigReal(); //default constructor
	BigReal(const string& real); //parameterized constructor
	BigReal operator +( BigReal& otherBigReal); //addition operator overload
	BigReal operator -(const BigReal& otherBigReal); //substraction operator overload
	BigReal operator ==(const BigReal& otherBigReal); //equality operator overload
	BigReal operator >(const BigReal& otherBigReal); //greater than operator overload
	BigReal operator <(const BigReal& otherBigReal); //smaller than operator overload
	BigReal& operator =(const string& BigR); //assignment operator overload
	friend istream& operator >>(istream& input, BigReal& bigR); //friend function (bec we're using istream) insertion operator overload
	friend ostream& operator<<(ostream& output, const BigReal& BigR); //friend function (bec we're using ostream) extraction operator overload
};

