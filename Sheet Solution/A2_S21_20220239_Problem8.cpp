// File: A2_S21_20220239_Problem8.cpp
// Purpose: Solution for sheet 1
// Author: Ghassan Tarek Elgendy
// Section: S21
// ID: 20220239
// TA: Rana AbdelKader
// Date: 29 Oct 2023

#include <bits/stdc++.h>
#define End return 0;
using namespace std;

void pattern(int n, int i) {
    if (!n) return; //base case
    pattern(n / 2, i); //start from 0 to generate the upper half
    for (int j = 0; j < i; j++) cout << "  "; //offsetting the column
    for (int k = 0; k < n; k++) cout << "* "; //printing the row
    cout << '\n';//newline 
    pattern(n / 2, i + n / 2); //printing the lower part 
}

int main() {
    cout << "Enter a power of 2 number & a column to start in:\n";
    int n, i;
    cin >> n >> i;
    pattern(n, i);
    End
}
