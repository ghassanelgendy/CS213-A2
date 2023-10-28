#include <iostream>
using namespace std;

string replacePronounce(string &s) {
    string newS = " ";
    for (int i = 0; i < s.size(); ++i) {
        newS += s[i];
        if (s[i - 2] == ' ' && (s[i - 1] == 'h' || s[i - 1] == 'H') && s[i] == 'e')
            newS += " or she";
        if (s[i - 3] == ' ' && (s[i - 2] == 'h' || s[i - 2] == 'H') && s[i - 1] == 'i' && s[i] == 'm')
            newS += " or her";
    }
    return newS;
}

int main() {
    string s;
    getline(cin, s);
    cout << replacePronounce(s);
    return 0;
}