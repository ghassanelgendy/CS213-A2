#pragma once
#include <string>
#include <regex>
#include <iostream>
using namespace std;
class Instruction
{
protected:
	char opCode;  
	string operand;
public:
	Instruction(string instIn);
	bool validateInstruction();
	void addInstruction();
	string toHex();
	unsigned short toBinary();
};

