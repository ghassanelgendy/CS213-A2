#pragma once
#include "Memory.h"
#include "Register.h"
#include "Instruction.h"
#include "Counter.h"
#include "IR.h"
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
	void loadInstructions(string filename);
	void clear();
	static string toHex(int dec);
	static int toDec(char x);
};

