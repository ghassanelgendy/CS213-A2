// File: Problem9.cpp
// Purpose: A game with teddy bears that detects whether you win or lose
// Author: Jana Ramadan
// Section: S21
// ID: 20220470
// TA: Rana Abdelkader
// Date: 12 Oct 2023
#include <iostream>
using namespace std;
static bool bears(int n) // ely ma3aya
{
    if(n==42){     // law maq3aya exactly 42 fa shokran keda khelset
        return true;
    }
    else{
        if(n%5==0){ // law divisible by 5 hatraga3 el n-42
            bears(n-42);
            return true;      // w leh return true la2n mafrod dy men el steps ely bet2ool eny on the right track
        }
        else if(n%2==0){
            bears(n/2);
            return true;
        }
        else if(n%3==0 || n%4==0)
        {
            int x = n%10; // last digit
            int y = (n%100)/10; // el digit ely abl el akheer
            bears(n-(x*y));
            return true;
        }
        else{
            return false;        // khalas keda mafehash wala wahda men el rules ely bet2ool eny haksab
        }
    }
}
int main()
{
    int n;  cin>>n;
    if(bears(n))
        cout << "You have reached the goal!";
    else{
        cout << "You lose";
    }
    return 0;
}


