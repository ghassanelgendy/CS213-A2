// File: A2_S21_20220239_Problem2.cpp
// Purpose: Solution for sheet 1
// Author: Ghassan Tarek Elgendy
// Section: S21
// ID: 20220239
// TA: Rana AbdelKader
// Date: 29 Oct 2023

#include <iostream>
#include <regex>
using namespace std;
string replacePronounce(string &s) {
    regex heReg("(\\bhe\\b|\\bHe\\b)"); //regex to check the existence of a "he" or "He" with non-letter boundaries
    regex himReg("(\\bhim\\b|\\bHim\\b)");
    string newS = regex_replace(s, heReg, "he or she"); //replacing he with he or she
    newS = regex_replace(newS, himReg, "him or her"); //replacing him with him or her
    return newS;
}
int main() {
    string s;
    getline(cin, s);
    cout << replacePronounce(s) << endl;
    return 0;
}
