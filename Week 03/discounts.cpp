#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// https://www.hackerrank.com/contests/practice-1-si/challenges/task-2-1-1/problem

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


    int counter = 0;

    int total = 0;

    for (int i = n-1; i >= 0; i--)
    {
        total += input[i];
        counter++;

        if (counter == k)
        {
            total -= input[i];
            counter = 0;
        }
    }
    cout << total;
    return 0;
}
