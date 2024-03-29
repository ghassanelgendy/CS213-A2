// File: A2_S21_20220239_Problem11.cpp
// Purpose: Solution for sheet 1
// Author: Ghassan Tarek Elgendy
// Section: S21
// ID: 20220239
// TA: Rana AbdelKader
// Date: 29 Oct 2023

#include <bits/stdc++.h>
/*
(a) In case of character by character comparison, the program will display if the files are identical, or it
will display the number and the content of the first line that is different. White spaces are compared.

(b) In case of word by word, white spaces, tabs and new lines are ignored and files are compared word
by word. The result is either identical or the first different word and the line that contains it.
*/
using namespace std;
bool isSame{true};
ifstream f1; //ifstream obj
int size1; //first obj's size
int size2; //sec obj's size
ifstream f2; 

int getSize(ifstream &filename) {
    long long size;
    filename.seekg(0, std::ifstream::end); //seeking to the end of the file to get size
    size = filename.tellg();
    filename.seekg(0, std::ifstream::beg); //going back to the beginning
    return (int) size;
}

string openFile(const string &filename) {
    return filename + ".txt"; //appending .txt to the input
}

void compareChar() {
    char ch1, ch2; 
    int diff = 0;
    while (f1.get(ch1) && f2.get(ch2)) { //while there's still characters in both files
        if (ch1 != ch2) { //comparing each character
            isSame = false;  
            diff++; //incrementing the difference between them
        }
    }
    if (!isSame || (f1.get(ch1) || f2.get(ch2))) { //if they're not the same but there's a file bigger than the other
        diff += abs(size1 - size2); //taking the absolute for the differences between both files and considering them as differences  
        cout << "Number of differences = " << diff;  
    } else
        cout << "These are identical.\n";
}

void compareWord() {
    string s1, s2;
    while ((f1 >> s1) && (f2 >> s2)) {
        if (s1 != s2) {
            isSame = false;
            cout << "Difference in the 1st file: " << s1 << " and in the 2nd one: " << s2 << '\n';
            break;
        }
    }
    if (isSame)
        cout << "These are identical.\n";
}

void userChoice() {

    cout << "Please enter the two files' names\n"
            " First file name: ";
    string name;
    cin >> name;
    f1.open(openFile(name));
    size1 = getSize(f1);
    cout << "Second file name: ";
    cin >> name;
    f2.open(openFile(name));
    size2 = getSize(f2);
    start:
    cout << "What do you wanna do?\n";
    cout << "a. Compare two files word by word\n"
            "b. Compare two files character by character\n";
    unsigned char choice;
    cin >> choice;
    choice = tolower(choice);
    if (choice == 'a') {
        compareWord();
    } else if (choice == 'b') {
        compareChar();
    } else {
        cout << "Wrong entry, try again.\n";
        goto start;
    }
}

int main() {
    cout << "\t\t=============[ Welcome to the file comparison utility ]=============\n";
    userChoice();
    return 0;
}
