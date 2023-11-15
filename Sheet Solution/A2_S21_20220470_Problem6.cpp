// File: Problem6.cpp
// Purpose: 2 printing functions (one to print the value of n as binary and the other to print all possible combinations of the prefix and k-digit suffix)
// Author: Jana Ramadan
// Section: S21
// ID: 20220470
// TA: Rana Abdelkader
// Date: 12 Oct 2023
#include <iostream>
using namespace std;
static void binaryPrint(int n){
    if (n == 0 || n==1){
        cout << n;
        return;
    }
    else{
        binaryPrint(n / 2); // back again but this time with n/2
        cout << (n % 2); // printing the reminder
    }
}
static void numbers(string prefix, int k) { // 00101 k=2 0010100 0010101 0010110 0010111
    if (k == 0) {             // Nothing to be added
        cout <<prefix << endl;
        return;
    }
    numbers(prefix + "0", k - 1);  //adding zeros till the base case is reached
    numbers(prefix + "1", k - 1);  // adding ones till the base case is reached
}
int main() {
    cout << "Type (1) to use binary print function or type (2) to use numbers function: ";
    int x; cin>>x;
    if(x ==1){
        int n;
        cin>>n;
        binaryPrint(n);
    }
    else if(x == 2){
        string prefix;
        cin>>prefix;
        int k;
        cin>>k;
        numbers(prefix,k);
    }
    return 0;
}
