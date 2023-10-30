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
  
    BigReal n1("11.9000000000000000000000000000000001");
    BigReal n2("2333333333339.1134322222222292");
    BigReal n3 = n1 + n2;
    cout << n3;
    //BigReal R;
    //BigReal K;
    //BigReal w; //from default constructor
    //cout << w;
    //K = "43"; //from assignment operator
    //cin >> R; //the insertion operator
    //cout << "K = " << K << '\n'<< //extraction operator
    //        "R = " << R;
}