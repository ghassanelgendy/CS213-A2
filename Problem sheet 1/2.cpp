#include <iostream>
#include <regex>
using namespace std;
string replacePronounce(string &s) {
    regex heReg("(\\bhe\\b|\\bHe\\b)"); //regex to check the existence of a "he" or "He" with non-letter boundaries
    regex himReg("(\\bhim\\b|\\bHim\\b)");
    string newS = regex_replace(s, heReg, "he or she");
    newS = regex_replace(newS, himReg, "him or her");
    return newS;
}
int main() {
    string s;
    getline(cin, s);
    cout << replacePronounce(s) << endl;
    return 0;
}