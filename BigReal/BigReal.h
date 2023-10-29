#include <vector>
#include <string>

using namespace std;
#pragma once
class BigReal
{
private:
	char sign = '+';
	char dot = '.';
	string integer;
	string fraction;
public:
	BigReal();
	BigReal(string real);
	BigReal operator +(BigReal& otherBigReal);
	BigReal operator -(BigReal& otherBigReal);
	BigReal operator ==(BigReal& otherBigReal);
	BigReal operator >(BigReal& otherBigReal);
	BigReal operator <(BigReal& otherBigReal);
	void print();
};

