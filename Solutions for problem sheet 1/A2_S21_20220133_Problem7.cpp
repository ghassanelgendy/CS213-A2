// File: problem7.cpp
// Purpose: program that a) returns true if it's possible to build a chain consisting of every domino
//                       b)Print the solution of the domino chain
// Author: Rawan Ehab
// Section: S21
// ID: 20220133
// TA: Rana Abdelkader
// Date: 12 Oct 2023
#include <iostream>
#include <vector>
using namespace std;

struct dominoT {
    int leftDots;
    int rightDots;
};

bool FormsDominoChain(vector<dominoT> & dominos, vector<dominoT> & chain){
    if (dominos.empty()) { //recursion base case , if we have no dominos left to check and none of them returned false
        return true;
    }
    for (int i = 0; i < dominos.size(); ++i) {
        if(chain.empty() || chain.back().rightDots == dominos[i].leftDots) {
            chain.push_back(dominos[i]);
            dominoT current = dominos[i]; //save the current domino temporarily in case we need to backtrack
            dominos.erase(dominos.begin() + i);
            if (FormsDominoChain(dominos, chain)) { //calls functon recursively to check rest of the dominos
                return true;
            }
            dominos.insert(dominos.begin() + i, current);//backtracks if we cant form a chain this way
            chain.pop_back();
        }
    }

    return false;
}

void printsol(const vector<dominoT> & chain) {
    for (const auto & domino : chain) {
        cout << domino.leftDots << "|" << domino.rightDots << " - ";
    }
}

int main() {
    vector<dominoT> set;
    int n;
    cout << "Enter number of dominos\n";
    cin >> n;
    cout << "Enter the left and right dots of each domino:\n";
    for(int i = 0; i < n; ++i) {
        dominoT d;
        cout<<"left dots:\n";
        cin >> d.leftDots ;
        cout<<"right dots:\n";
        cin>> d.rightDots;
        set.push_back(d);
    }

    vector<dominoT> chain;
    if (FormsDominoChain(set, chain)) {
        cout<<"true\n";
        printsol(chain);
    } else {
        cout<<"false\n";
    }
}
//sheet test case input
//5
//1
//4
//2
//6
//4
//4
//6
//1
//4
//3
//{6, 1},{2, 6}, {1, 4}, {4, 4}, {4, 3}