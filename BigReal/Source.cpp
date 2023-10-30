// File: Source.cpp
// Purpose: This file contains the 'main' function. Program execution begins and ends there.
// Authors: Ghassan Elgendy - Rawan Ehab - Jana Ramadan
// IDs:	       20220239     -  20220133  -   20220270
// Section: S21
// TA: Rana Abdelkader
// Date: 30 Oct 2023
#include "BigReal.h"
#include <iostream>
using namespace std;
int main()
{
    BigReal R;
    BigReal K;
    BigReal w; //from default constructor
    cout << w;
    K = "43"; //from assignment operator
    cin >> R; //the insertion operator
    cout << "K = " << K << '\n'<< //extraction operator
            "R = " << R;
}