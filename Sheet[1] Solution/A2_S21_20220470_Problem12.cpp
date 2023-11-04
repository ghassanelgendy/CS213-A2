// File: Problem12.cpp
// Purpose: Scans a file for some terms.
// Author: Jana Ramadan
// Section: S21
// ID: 20220470
// TA: Rana Abdelkader
// Date: 12 Oct 2023
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
vector<string> words = {"suspicious", "expire", "important", "install", "bank", "locked", "PIN", "password", "personal","update", "action", "required", "invoice", "hello", "credit", "card", "verification ", "account", "security", "confirm", "link", "online", "transactions", "previous", "activity", "click", "download", "alert", "username", "perform"};
vector <int> points = {1,2,2,2,3,1,3,3,2,2,1,1,3,1,3,3,2,2,1,2,2,1,3,1,2,3,2,2,3,1};
void Phishing_Scanner() {
    ifstream file("Problem12.txt");  // opening the file
    if (file.is_open()) { // if the file is successfully opened
        string line;
        int total = 0;
        for (int i = 0; i < words.size(); i++) {
            file.clear(); // clear the end of file flag
            file.seekg(0, ios::beg); // move the file pointer to the beginning
            int count = 0;  // To calculate the count of every word
            while (getline(file, line)) { // reading all the lines in the file
                if (line.find(words[i]) != string::npos) {  // if the word is present in the file
                    count ++;
                    total += points[i];
                }
            }
            if (count != 0){
                cout <<words[i] << ": was found " << count << " times and its total number of points equals: " << (count*points[i]) << endl;
            }
        }
        cout << "Total of points: " << total << endl;
    }
    else {   // The file cannot be opened
        cout << "el file mesh motah" << endl;
    }
}
int main()
{
    Phishing_Scanner();
    return 0;
}
