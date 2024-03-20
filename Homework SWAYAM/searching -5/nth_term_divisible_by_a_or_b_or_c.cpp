#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
} 
int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}
int divTermCount(int a, int b, int c, int num)
{
    return ((num / a) + (num / b) + (num / c) - (num / lcm(a, b)) - (num / lcm(b, c)) - (num / lcm(a, c)) + (num / lcm(a, lcm(b, c))));
}
int findNthTerm(int a, int b, int c, int n)
{
    int low = 1, high = INT_MAX, mid;
 
    while (low < high) {
        mid = low + (high - low) / 2;
        if (divTermCount(a, b, c, mid) < n)
            low = mid + 1;
        else
            high = mid;
    }
 
    return low;
}
 