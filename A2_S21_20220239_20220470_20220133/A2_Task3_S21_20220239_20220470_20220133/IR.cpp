// File: IR.cpp
// Authors: Ghassan Elgendy - Rawan Ehab - Jana Ramadan
// IDs:	       20220239     -  20220133  -   20220470
// Section: S21
// TA: Rana Abdelkader
// Date: 15 Nov 2023
#include "IR.h"

void IR::setInstruction(Instruction inst)
{
    opCode = inst.getOpCode();
    operand = inst.getOperand();
}
IR::IR(){}
IR::IR(string instIn,string a) : Instruction(instIn,a){}
string IR::getInstruction()
{
    string s{ "" };
    s = s + opCode + operand;
    return s;
}