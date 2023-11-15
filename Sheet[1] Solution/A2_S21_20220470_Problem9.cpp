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
    if(n==42){
        return true; // as exactly 42 means winning
    }
    else{
        if(n%5==0){ //if it is divisible by 5 we should go back but this time with n-42
            bears(n-42);
            return true;
        }
        else if(n%2==0){   //if it is divisible by 2 we should go back but this time with n/2
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
            return false;     // All the possible steps to win are not present therefore returning false is a must
        }
    }
}
int main()
{
    int n;  cin>>n;
    if(bears(n))
        cout << "You have reached the goal!";
    else{
        cout << "You lose!";
    }
    return 0;
}


