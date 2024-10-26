#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://www.hackerrank.com/contests/sda-ttest-2/challenges/challenge-1636/problem

pair<int, int> binary(const vector<int>& nums, int target)
{
    int l = 0;
    int r = nums.size() - 1;

    int counter = 1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (nums[mid] == target)
        {
            return { mid, counter };
        }
        else if (nums[mid] < target)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }

        counter++;
    }

    return { -1, counter-1 };
}

int main()
{
    int N = 0, K = 0;
    cin >> N;

    vector<int> nums(N);

    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    vector<pair<int, int>> binaryRes;
    cin >> K;
    int cpyK = K;
    while (K--)
    {
        int temp = 0;
        cin >> temp;

        binaryRes.push_back(binary(nums, temp));
    }

    for (int i = 0; i < cpyK; i++)
    {
        cout << binaryRes[i].first << ' ';
    }
    cout << '\n';
    for (int i = 0; i < cpyK; i++)
    {
        cout << binaryRes[i].second << ' ';
    }

    return 0;
}
