// File: Problem3.cpp
// Purpose: Extracts the wanted word from the target string.
// Author: Jana Ramadan
// Section: S21
// ID: 20220470
// TA: Rana Abdelkader
// Date: 12 Oct 2023
#include <iostream>
#include <vector>
using namespace std;
vector <string> split(string target,string delimiter){
    vector<string> result;
    getline(cin,target);
    cin>> delimiter;
    for(int i=0;i<target.size();++i)
    {
        if(target[i] != delimiter[0]){
            result.push_back(string(1, target[i]));   // if they are not equal a string is created with the wanted character only repeated once
        }
        else{
            result.push_back(string(1,' ')); // adding spaces in between
        }
    }
    for(int i=0;i<result.size();++i){
        cout << result[i];
    }
    return result;
}
int main(){
    string target, delimiter;
    split(target,delimiter);
    return 0;
}
