// File: Source.cpp
// Purpose: This file contains the 'main' function. Program execution begins and ends there.
// Authors: Ghassan Elgendy - Rawan Ehab - Jana Ramadan
// IDs:	       20220239     -  20220133  -   20220470
// Section: S21
// TA: Rana Abdelkader
// Date: 30 Oct 2023
#include <iostream>
#include "BigReal.h"

using namespace std;

int main() {
    BigReal a("0");
    BigReal b("123.456");
    BigReal c("12.34");

    // Test 1: Parameterized Constructor
    cout << "Test 1: Parameterized Constructor" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    cout << '\n';
    // Test 2: Copy Assignment Operator
    a = b;
    cout << "Test 2: Copy Assignment Operator" << endl;
    cout << "a = " << a << " (Expected: 123.456)" << endl;

    cout << '\n';
    // Test 3: Equality Operator
    bool isABEqual = (a == b);
    bool isACEqual = (a == c);
    cout << "Test 3: Equality Operator" << endl;
    cout << "a == b: " << isABEqual << " (Expected: 1, true)" << endl;
    cout << "a == c: " << isACEqual << " (Expected: 0, false)" << endl;

    cout << '\n';
    // Test 4: Less Than Operator
    bool isALessThanB = (a < b);
    bool isALessThanC = (a < c);
    bool isCLessThanA = (c < a);
    cout << "Test 4: Less Than Operator" << endl;
    cout << "a < b: " << isALessThanB << " (Expected: 0, false)" << endl;
    cout << "a < c: " << isALessThanC << " (Expected: 0, false)" << endl;
    cout << "c < a: " << isCLessThanA << " (Expected: 1, true)" << endl;

    cout << '\n';
    // Test 5: Greater Than Operator
    bool isAGreaterThanB = (a > b);
    bool isAGreaterThanC = (a > c);
    bool isCGreaterThanA = (c > a);
    cout << "Test 5: Greater Than Operator" << endl;
    cout << "a > b: " << isAGreaterThanB << " (Expected: 0, false)" << endl;
    cout << "a > c: " << isAGreaterThanC << " (Expected: 1, true)" << endl;
    cout << "c > a: " << isCGreaterThanA << " (Expected: 0, false)" << endl;

    cout << '\n';
    // Test 6: Addition Operator
    BigReal d = (a + b);
    cout << "Test 6: Addition Operator" << endl;
    cout << "d = " << d << " (Expected: 246.912)" << endl;

    cout << '\n';
    // Test 7: Subtraction Operator
    BigReal e("0.0");

    // Test 7: Assignment Operator
    e = "0.0";
    cout << "Test 7: Subtraction Operator" << endl;
    cout << "e = " << e << " (Expected: 0)" << endl;

    cout << '\n';
    // Test 8: Input Operator
    cout << "Test 8: Input Operator" << endl;
    cout << "Enter a BigReal number: ";
    cin >> a;
    cout << "You entered: " << a << endl;

    cout << '\n';
    // Test 9: Additional Arithmetic Test Cases
    BigReal x("123456789.987654321");
    BigReal y("87654321.123456789");
    BigReal z = x + y;
    cout << "Test 9: Additional Arithmetic Test Cases" << endl;
    cout << "x + y = " << z << " (Expected: 211111111.111111110)" << endl;

    BigReal i("987654321.123456789");
    BigReal o("123456789.987654321");
    BigReal p = i - o;
    cout << "i - o = " << p << " (Expected: 864197531.135802468)" << endl;

    BigReal g("123456789.987654321");
    BigReal h("-87654321.123456789");
    BigReal m = g + h;
    cout << "g + h = " << m << " (Expected: 35802468.864197532)" << endl;

    BigReal j("987654321.123456789");
    BigReal k("-123456789.987654321");
    BigReal l = j - k;
    cout << "j - k = " << l << " (Expected: 1111111111.11111111)" << endl;
    // Test 10: Adding a positive and a negative BigReal number
    BigReal n("123.456");
    BigReal f("-12.34");
    BigReal result1 = n + f;
    cout << "Test 10: Adding a positive and a negative number" << endl;
    cout << "n = " << n << ", f = " << f << endl;
    cout << "n + f = " << result1 << " (Expected: 111.116)" << endl;

    cout << '\n';
    // Test 11: Subtracting a negative number from a positive number
    BigReal positive("123.456");
    BigReal negative("-12.34");
    BigReal result2 = positive - negative;
    cout << "Test 11: Subtracting a negative number from a positive number" << endl;
    cout << "positive = " << positive << ", negative = " << negative << endl;
    cout << "positive - negative = " << result2 << " (Expected: 135.796)" << endl;

    cout << '\n';
    // Test 12: Adding two negative BigReal numbers
    BigReal neg1("-123.456");
    BigReal neg2("-12.34");
    BigReal result3 = neg1 + neg2;
    cout << "Test 12: Adding two negative numbers" << endl;
    cout << "neg1 = " << neg1 << ", neg2 = " << neg2 << endl;
    cout << "neg1 + neg2 = " << result3 << " (Expected: -135.796)" << endl;

    cout << '\n';
    // Test 13: Subtracting a positive number from a negative number
    BigReal neg3("-123.456");
    BigReal pos("12.34");
    BigReal result4 = neg3 - pos;
    cout << "Test 13: Subtracting a positive number from a negative number" << endl;
    cout << "neg3 = " << neg3 << ", pos = " << pos << endl;
    cout << "neg3 - pos = " << result4 << " (Expected: -135.796)" << endl;
    cout << '\n';

    // Test 14: Adding a very large positive number to a very small negative number
    BigReal largePositive("9999999999999999999999999999999.123456789");
    BigReal smallNegative("-0.0000000000000000000000000000001");
    BigReal result5 = largePositive + smallNegative;
    cout << "Test 14: Adding a large positive number to a small negative number" << endl;
    cout << "largePositive = " << largePositive << ", smallNegative = " << smallNegative << endl;
    cout << "largePositive + smallNegative = " << result5 << " (9999999999999999999999999999999.1234567889999999999999999999999)" << endl;
    cout << '\n';
    // Test 15: Subtracting a very large negative number from a very small positive number
    BigReal smallPositive("0.0000000000000000000000000000001");
    BigReal largeNegative("-9999999999999999999999999999999.123456789");
    BigReal result6 = smallPositive - largeNegative;
    cout << "Test 15: Subtracting a small positive number from a large negative number" << endl;
    cout << "smallPositive = " << smallPositive << ", largeNegative = " << largeNegative << endl;
    cout << "smallPositive - largeNegative = " << result6 << " (Expected: 9999999999999999999999999999999.1234567890000000000000000000001)" << endl;
    cout << '\n';
    // Test 16: Additional Arithmetic Test Cases
    BigReal x0("36547854.3614");
    BigReal y0("514785269.96321");
    BigReal result7 = x0 + y0;
    cout << "Test 16: Adding x and y" << endl;
    cout << "x = " << x0 << ", y = " << y0 << endl;
    cout << "x + y = " << result7 << " (Expected: 551333124.32461)" << endl;
    cout << '\n';

    BigReal x2("-36547854.3614");
    BigReal y2("514785269.96321");
    BigReal result8 = x2 + y2;
    cout << "Test 17: Adding x2 and y2" << endl;
    cout << "x2 = " << x2 << ", y2 = " << y2 << endl;
    cout << "x2 + y2 = " << result8 << " (Expected: 478237415.6018)" << endl;
    cout << '\n';

    BigReal x3("36547854.3614");
    BigReal y3("-514785269.96321");
    BigReal result9 = x3 + y3;
    cout << "Test 18: Adding x3 and y3" << endl;
    cout << "x3 = " << x3 << ", y3 = " << y3 << endl;
    cout << "x3 + y3 = " << result9 << " (Expected: -478237415.60181)" << endl;
    cout << '\n';

    BigReal x4("-36547854.3614");
    BigReal y4("-514785269.96321");
    BigReal result10 = x4 + y4;
    cout << "Test 19: Adding x4 and y4" << endl;
    cout << "x4 = " << x4 << ", y4 = " << y4 << endl;
    cout << "x4 + y4 = " << result10 << " (Expected: -551333124.32461)" << endl;
    cout << '\n';

    BigReal x5("514785269.96321");
    BigReal y5("36547854.3614");
    BigReal result11 = x5 + y5;
    cout << "Test 20: Adding x5 and y5" << endl;
    cout << "x5 = " << x5 << ", y5 = " << y5 << endl;
    cout << "x5 + y5 = " << result11 << " (Expected: 551333124.32461)" << endl;
    cout << '\n';

    BigReal x6("-514785269.96321");
    BigReal y6("36547854.3614");
    BigReal result12 = x6 + y6;
    cout << "Test 21: Adding x6 and y6" << endl;
    cout << "x6 = " << x6 << ", y6 = " << y6 << endl;
    cout << "x6 + y6 = " << result12 << " (Expected: -478237415.60181)" << endl;
    cout << '\n';

    BigReal x7("514785269.96321");
    BigReal y7("-36547854.3614");
    BigReal result13 = x7 + y7;
    cout << "Test 22: Adding x7 and y7" << endl;
    cout << "x7 = " << x7 << ", y7 = " << y7 << endl;
    cout << "x7 + y7 = " << result13 << " (Expected: 478237415.60181)" << endl;
    cout << '\n';

    BigReal x8("-514785269.96321");
    BigReal y8("-36547854.3614");
    BigReal result14 = x8 + y8;
    cout << "Test 23: Adding x8 and y8" << endl;
    cout << "x8 = " << x8 << ", y8 = " << y8 << endl;
    cout << "x8 + y8 = " << result14 << " (Expected: -551333124.32461)" << endl;

    return 0;
}

