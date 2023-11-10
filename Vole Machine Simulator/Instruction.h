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
	Instruction();
	Instruction(string instIn);
	bool validateInstruction();
	string getCode();
	char getOpCode();
	string getOperand();
};

