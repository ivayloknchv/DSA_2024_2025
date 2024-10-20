// https://www.hackerrank.com/contests/24-25-1/challenges/walking-median-sorting

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int main()
{
    cin >> N;
    vector<int> nums(N);

    for (int i = 0; i < N; i++)
    {
        int temp;

        cin >> temp;

        int idx = i - 1;

        while (idx >= 0 && temp < nums[idx])
        {
            nums[idx + 1] = nums[idx];
            idx--;
        }
        nums[++idx] = temp;

        if ((i+1) % 2 == 1)
        {
            int idx = (1 + i+1) / 2 - 1;

            cout << nums[idx] << '\n';
        }

        else
        {
            int idx = (1 + i+1) / 2 - 1;

            cout << (nums[idx] + nums[idx + 1]) / 2.00 << '\n';
        }
    }
    return 0;
}
