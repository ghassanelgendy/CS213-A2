#pragma once
#include "Instruction.h"
class IR : public Instruction
{
public:
	IR();
	IR(string instIn, string a);
	void setInstruction(Instruction inst);
	string getInstruction();
};

