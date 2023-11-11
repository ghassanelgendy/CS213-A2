#include "IR.h"

void IR::setInstruction(Instruction inst)
{
    opCode = inst.getOpCode();
    operand = inst.getOperand();
}
IR::IR()
{
}
IR::IR(string instIn) : Instruction(instIn){
    //Instruction::Instruction(instIn);
}
string IR::getInstruction()
{
    string s{ "" };
    s = s + opCode + operand;
    return s;
}