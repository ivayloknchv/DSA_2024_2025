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
    vector<int> nums;

    int temp = 0;
    cin >> temp;

    nums.push_back(temp);
    cout << nums[0] << '\n';

    for (int i = 1; i < N; i++)
    {
        cin >> temp;

        int idx = 0;

        for (int j = 0; j < i; j++)
        {
            if (temp > nums[j])
            {
                idx++;
            }
        }

        nums.insert(nums.begin() + idx, temp);

        if (nums.size() % 2 == 1)
        {
            int idx = (1 + nums.size()) / 2 - 1;

            cout << nums[idx] << '\n';
        }

        else
        {
            int idx = (1 + nums.size()) / 2 - 1;

            cout << (nums[idx] + nums[idx + 1]) / 2.00 << '\n';
        }
    }
    return 0;
}

