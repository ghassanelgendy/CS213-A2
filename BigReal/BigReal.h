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
	BigReal operator +(const BigReal& otherBigReal); //addition opertator overload
	BigReal operator -(const BigReal& otherBigReal); //substraction opertator overload
	BigReal operator ==(const BigReal& otherBigReal); //equality opertator overload
	BigReal operator >(const BigReal& otherBigReal); //greater than opertator overload
	BigReal operator <(const BigReal& otherBigReal); //smaller than opertator overload
	BigReal& operator =(const string& BigR); //assignment opertator overload
	friend istream& operator >>(istream& input, BigReal& bigR); //friend function (bec we're using istream) insertion operator overload
	friend ostream& operator<<(ostream& output, const BigReal& BigR); //friend function (bec we're using ostream) extraction operator overload
};

