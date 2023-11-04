// File: Source.cpp
// Purpose: This file contains the 'main' function. Program execution begins and ends there.
// Authors: Ghassan Elgendy - Rawan Ehab - Jana Ramadan
// IDs:	       20220239     -  20220133  -   20220470
// Section: S21
// TA: Rana Abdelkader
// Date: 30 Oct 2023
#include "BigReal.h"
#include <iostream>
using namespace std;
int main()
{
    //BigReal x("36547854.3614") , y("514785269.96321");             // SUB: -478,237,415.60181  ,ADD: 551,333,124.3246     //SHA8ALBOTH
    //BigReal x("-36547854.3614") , y("514785269.96321");           // SUB:-551,333,124.32461    ,ADD: 478,237,415.6018     //SHA8ALBOTH
	//BigReal x("36547854.3614") , y("-514785269.96321");          //SUB:551,333,124.32461       ,ADD: -478,237,415.60181   //SHA8ALBOTH
	//BigReal x("-36547854.3614") , y("-514785269.96321");        //SUB:478,237,415.60181        ,ADD:-551,333,124.32461    //SHA8ALBOTH
	//BigReal x("514785269.96321") , y("36547854.3614");         //SUB:478,237,415.60181         ,ADD:  551,333,124.32461   //SHA8ALBOTH
	//BigReal x("-514785269.96321"), y("36547854.3614");        //SUB:-551,333,124.32461         ,ADD:-478,237,415.60181    //SHA8ALBOTH
	//BigReal x("514785269.96321"), y("-36547854.3614");       //SUB:551,333,124.32461           ,ADD:478,237,415.60181     //SHA8ALBOTH
	BigReal x("-514785269.96321"), y("-36547854.3614");      //SUB:-478,237,415.60181          ,ADD:-551,333,124.32461      //SHA8ALBOTH


     cout << (x + y) << endl;
	
    // //TEST CASES
    //BigReal x("514785269.96321"), y("36547854.3614");

    //// Addition
    //BigReal add_result = x + y;
    //cout << "Addition: " << x << " + " << y << " = " << x+y << endl;

    //// Subtraction
    //cout << "Subtraction: " << x << " - " << y << " = " << x-y << endl;

    //// Greater than
    //cout << "Greater than: " << x << " > " << y << " = " << (x > y) << endl;

    //// Less than
    //cout << "Less than: " << x << " < " << y << " = " << (x < y) << endl;

    //return 0;

	


}