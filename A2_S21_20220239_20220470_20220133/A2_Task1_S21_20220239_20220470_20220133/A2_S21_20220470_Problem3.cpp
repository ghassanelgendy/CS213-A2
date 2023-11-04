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
vector <char> result;
vector <string> split(string target,string delimiter){
    getline(cin,target);
    cin>> delimiter;
    for(int i=0;i<target.size();++i){
        if(target[i]!=delimiter[0])
            result.push_back(target[i]);// elstring ely ana 3ayza
        else
            result.push_back(' '); // spaces bas fel nos 3ashan el kalam maylaza2sh fy ba3d
    }
    for (int i=0;i<result.size();++i){
        cout << result[i];   // ben print elvector ba
    }
}
int main(){
    string target, delimiter;
    split(target,delimiter);
    return 0;
}

