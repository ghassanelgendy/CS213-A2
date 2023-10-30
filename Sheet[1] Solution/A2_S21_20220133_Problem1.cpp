// File: problem1.cpp
// Purpose: reads in a sentence of up to 100 characters and outputs the sentence with spacing
//          corrected and with letters corrected for capitalization.
// Author: Rawan Ehab
// Section: S21
// ID: 20220133
// TA: Rana Abdelkader
// Date: 12 Oct 2023
#include <iostream>
#include <string>

using namespace std;
string new_sentence(string input){
    input[0] = toupper(input[0]);
    for (int i = 1; i < input.length(); i++) {
        input[i] = tolower(input[i]);
    }
    int i = 0;
    while (i < input.length()) {
        if (input[i] == ' ' && input[i+1] == ' ') {
            input.erase(i,1);
            i = 0;  // to start the loop from the beginning again after every double space
        } else {
            i++;
        }
    }
    return input;
}
int main() {
    string input;
    getline(cin,input); //because cin reads only first word
    cout<<new_sentence(input);

    return 0;
}
