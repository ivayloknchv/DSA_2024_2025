#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    vector<pair<int, int>> targets;

    targets.push_back({ 0,0 });
    for (int i = 1; i <= 20; i++)
    {
        targets.push_back({ i,1 });
    }

    targets.push_back({ 25,1 });

    for (int i = 1; i <= 20; i++)
    {
        targets.push_back({ i ,2 });
    }

    targets.push_back({ 25,2 });

    for (int i = 1; i <= 20; i++)
    {
        targets.push_back({ i ,3 });
    }

    cin >> N;
    int ans = 0;

    for (int i = 22; i < 43; i++)
    {
        if (N == targets[i].first * targets[i].second)
        {
            ans++;
        }
    }

    for (size_t i = 0; i < targets.size(); i++)
    {
        for (int j= 22; j < 43; j++)
        {
            if (N == (targets[i].first * targets[i].second + targets[j].first * targets[j].second))
            {
                ans++;
            }
        }
    }

    for (size_t i = 0; i < targets.size(); i++)
    {
        for (size_t j = 0; j < targets.size(); j++)
        {
            for (int k = 22; k < 43; k++)
            {
                if (N == (targets[i].first * targets[i].second + targets[j].first * targets[j].second + targets[k].first*targets[k].second))
                {
                    ans++;
                }
            }
        }
    }

    cout << ans;

    return 0;
}

