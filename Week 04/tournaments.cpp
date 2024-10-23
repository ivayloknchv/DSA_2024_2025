#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// https://www.hackerrank.com/contests/sda-24-25-2/challenges/challenge-3669/problem

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N = 0, Q = 0, minWeight = 0, maxWeight = 0;
    cin >> N >> Q;

    vector<int> participants(N);

    for (int i = 0; i < N; i++)
    {
        cin >> participants[i];
    }

    sort(participants.begin(), participants.end());

    while (Q--)
    {
        cin >> minWeight >> maxWeight;
        
        if(minWeight>maxWeight)
        {
            cout<<0<<'\n';
            continue;
        }

        auto start = lower_bound(participants.begin(), participants.end(), minWeight);
        auto end = upper_bound(participants.begin(), participants.end(), maxWeight);

        cout << distance(start,end) << '\n';
    }
    return 0;
}
