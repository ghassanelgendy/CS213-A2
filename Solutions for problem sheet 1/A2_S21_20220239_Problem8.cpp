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
    if (!n) return;
    pattern(n / 2, i);
    for (int j = 0; j < i; j++) cout << "  ";
    for (int k = 0; k < n; k++) cout << "* ";
    cout << '\n';
    pattern(n / 2, i + n / 2);
}

int main() {
    cout << "Enter a power of 2 number & a column to start in:\n";
    int n, i;
    cin >> n >> i;
    pattern(n, i);
    End
}