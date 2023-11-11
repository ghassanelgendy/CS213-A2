#include "Register.h"

Register::Register(string Address, string Value)
{
    value = Value;
    address = Address;
}

void Register::setValue(string Value)
{
    value = Value;
}

string Register::getValue()
{
    return value;
}

string Register::getAddress()
{
    return address;
}

void Register::clearReg()
{
    value = "00";
}

void Register::setAddress(string Address)
{
    address = Address;
}

Register::Register() { address = "", value = ""; }
