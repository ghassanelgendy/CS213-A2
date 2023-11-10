#include "Instruction.h"


Instruction::Instruction()
{
	
}

Instruction::Instruction(string instIn) :operand("")
{
	regex pattern("0x");
	string result = regex_replace(instIn, pattern, "");
	opCode = result[0];
	operand = operand + result[2] + result[4] + result[5];
	//cout << "opcode: " << opCode << endl << "operand: " << operand;
}

bool Instruction::validateInstruction()
{
	bool isValid{ false };
	if ((opCode > '0' && opCode <= '9') || (toupper(opCode) >= 'A' && toupper(opCode) < 'D')) {
		isValid = true;
	}
	else
		return 0;
	for (size_t i = 0; i < 3; i++)
	{
		if (operand[i] >= '0' && (operand[i] <= '9' || toupper(operand[i]) <= 'F')) {
			isValid = true;
		}
		else
			return 0;
	}
	return isValid;
}

string Instruction::getCode()
{
	return (opCode + operand);
}

char Instruction::getOpCode()
{
	return opCode;
}

string Instruction::getOperand()
{
	return operand;
}
