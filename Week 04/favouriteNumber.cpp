#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// https://www.hackerrank.com/contests/sda-24-25-2/challenges/challenge-3668/problem

unsigned long long ternaryReccursion(unsigned long long l, unsigned long long r, unsigned long long x, unsigned long long depth)
{
    if (l >= r)
    {
        return depth;
    }

    unsigned long long mid1 = l + (r - l) / 3;
    unsigned long long mid2 = r - (r - l) / 3;

    if (mid1 >= x)
    {
        return ternaryReccursion(l, mid1, x, depth+1);
    }

    else if(mid2 <= x)
    {
        return ternaryReccursion(mid2, r, x, depth+1);
    }
    
    return depth;

}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned long long p, n;
    cin >> p >> n;

    unsigned long long maxNum = pow(3, p);

    for(unsigned long long i = 0; i < n; i++)
    {
        unsigned long long current = 0;
        cin >> current;
        cout << ternaryReccursion(1, maxNum , current, 1) << '\n';
    }
    
    return 0;
}
