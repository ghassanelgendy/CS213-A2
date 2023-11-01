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
	//BigReal x("7.6"), y("6.4"); //1.2 //done
	BigReal x("7.6"), y("-6.4"); //14          //4?? //three digits wroking correctly???
	//BigReal x("-7.6"), y("106.4"); //-14     //-4?????
	//BigReal x("-7.6"), y("-6.4"); //-1.2    //done
	
	
    //BigReal x("6.4"), y("7.6"); //-1.2 //done
	//BigReal x("106.4"), y("-7.6"); //14   //4?? //three digits wrking correctly?????????????
	//BigReal x("-106.4"), y("7.6"); //-14  //-4???
	//BigReal x("-6.4"), y("-7.6"); //1.2  //done
	

	cout <<(x-y);
}
