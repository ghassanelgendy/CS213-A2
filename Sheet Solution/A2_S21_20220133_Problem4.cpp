// File: problem4.cpp
// Purpose: program that uses the sieve of Eratosthenes to generate a list of the primes between 2 and a given number n.
// Author: Rawan Ehab
// Section: S21
// ID: 20220133
// TA: Rana Abdelkader
// Date: 12 Oct 2023
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> prime;
    int n;
    cin >> n;
    int range[n-1];
    for (int i = 0; i < n-1; i++) {
        range[i] = i+2;
    }
    for (int i = 0; i <n-1 ; ++i) {
        int factor = 0;
        for (int j = 0; j < i; ++j) {
            if (range[i] % range[j] == 0) {
                factor++;
            }
        }
        if (factor == 0) {
            prime.push_back(range[i]);
        }
    }
    for (int i : prime)
        cout << i << " ";

    return 0;
}
