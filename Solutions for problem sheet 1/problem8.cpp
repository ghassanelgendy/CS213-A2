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