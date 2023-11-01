// File: BigReal.h
// Purpose: Header file for BigReal Class
// Authors: Ghassan Elgendy - Rawan Ehab - Jana Ramadan
// IDs:	       20220239     -  20220133  -   20220470
// Section: S21
// TA: Rana Abdelkader
// Date: 30 Oct 2023
#include <iostream>
#include <string>
#include <regex>
#include <string>
using namespace std;
#pragma once
class BigReal
{
private:
	bool isValidReal;
	bool isDot;
	char sign;
	string integer;
	string fraction; 
public:
	static void Pad(BigReal& a, BigReal& b);
	BigReal removeLead();
	BigReal(); //default constructor
	BigReal(const string& real); //parameterized constructor
	BigReal operator +(BigReal& otherBigReal); //addition operator overload
	BigReal operator -(const BigReal& otherBigReal); //substraction operator overload
	bool operator ==(BigReal& otherBigReal); //equality operator overload
	bool operator >(BigReal& otherBigReal); //greater than operator overload
	bool operator <(BigReal& otherBigReal); //smaller than operator overload
	BigReal& operator =(const string& BigR); //assignment operator overload
	friend istream& operator >>(istream& input, BigReal& bigR); //friend function (bec we're using istream) insertion operator overload
	friend ostream& operator<<(ostream& output, const BigReal& BigR); //friend function (bec we're using ostream) extraction operator overload
};

