// File: Register.cpp
// Authors: Ghassan Elgendy - Rawan Ehab - Jana Ramadan
// IDs:	       20220239     -  20220133  -   20220470
// Section: S21
// TA: Rana Abdelkader
// Date: 15 Nov 2023

#include "Register.h"

Register::Register(string Address, string Value)
{
    value = Value;
    address = Address;
}

void Register::setValue(string Value) {
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
