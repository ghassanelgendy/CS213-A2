#pragma once
#include "Memory.h"
#include "Register.h"
#include "Instruction.h"
#include "Counter.h"
#include "IR.h"
#include "Memory.cpp"
#include "Register.cpp"
#include "Instruction.cpp"
#include "Counter.cpp"
#include "IR.cpp"
#include <fstream>
#include <vector>

class Machine
{
	vector <Instruction> instructions;
	Memory memory[16][16];
	Register reg[16];
	IR instructionReg;
	Counter counter;
public:
	Machine();
	void excute();
	void print();
	void loadInstructions();
	void clear();
	static string toHex(int dec);
	static unsigned short toDec(string& hexString);
	static unsigned short toDec(char& hexChar);
    string binaryToHex(const string& binaryString);
    string addBinary(string a, string b);
    string int_to_binary(long long num);
    long binary_to_int(string Binary_num);
};

