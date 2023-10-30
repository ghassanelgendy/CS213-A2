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
        binaryPrint(n / 2); // bafdal a2sem a2sem a2sem w lazem dool yekono metratebeen keda 3ashan el reminder yegy metsha2leb
        cout << (n % 2);
    }
}
static void numbers(string prefix, int k) {
    if (k == 0) {             // keda keda mesh hazawed haga
        cout <<prefix << endl;
        return;
    }
    numbers(prefix + "0", k - 1);  //hayzawed zero  leghayet el base case
    numbers(prefix + "1", k - 1);
}
int main() {
    cout << "type (one) to print one number or (many) to print many numbers: ";
    string x; cin>>x;
    if(x =="one"){
        int n;
        cin>>n;
        binaryPrint(n);
    }
    else if(x == "many"){
        string prefix;
        cin>>prefix;
        int k;
        cin>>k;
        numbers(prefix,k);
    }
    return 0;
}
