// File: Register.h
// Authors: Ghassan Elgendy - Rawan Ehab - Jana Ramadan
// IDs:	       20220239     -  20220133  -   20220470
// Section: S21
// TA: Rana Abdelkader
// Date: 15 Nov 2023
#ifndef CS213_A2_REGISTER_H
#define CS213_A2_REGISTER_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Register
{
    string value;
    string address;

public:

    Register();
    Register(string Address, string Value);
    void setValue(string Value);
    void setAddress(string Address);
    string getValue();
    string getAddress();
    void clearReg();
};

#endif
