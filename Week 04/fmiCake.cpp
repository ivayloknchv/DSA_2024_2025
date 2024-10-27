using namespace std;
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

// https://www.hackerrank.com/contests/practice-3-1/challenges/fmicake/problem

int main()
{
    int T = 0;
    cin >> T;

    vector<int> res;

    while (T--)
    {
        int sweets = 0;
        cin >> sweets;
        int days = 0;

        while (sweets > 0)
        {
            int p = 0;
            if (sweets % 2 == 0)
            {
                p = sweets / 2;
            }
            else
            {
                p = sweets / 2;
                p += 1;
            }
            sweets -= p;
            days++;
        }

        res.push_back(days);

    }

    for (int day : res)
    {
        cout << day << '\n';
    }
    return 0;
}
