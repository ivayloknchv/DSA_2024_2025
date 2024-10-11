#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// https://www.hackerrank.com/contests/practice-1-si/challenges/task-4-1-1/problem

struct socksPair
{
    int left = 0;
    int right = 0;
};

bool operator < (const socksPair& lhs, const socksPair& rhs)
{
    int lhsDiff = abs(lhs.left - lhs.right);
    int rhsDiff = abs(rhs.left - rhs.right);

    return lhsDiff < rhsDiff || ((lhsDiff==rhsDiff) && lhs.left < rhs.left);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int>input;

    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        cin >> temp;
        input.push_back(temp);
    }

    sort(input.begin(), input.end());
    vector<socksPair>pairs;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            pairs.push_back({ input[i],input[j] });
        }
    }

    sort(pairs.begin(), pairs.end());

    cout << pairs[k - 1].left << ' ' << pairs[k - 1].right;
    return 0;
}
