#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// https://www.hackerrank.com/contests/sda-hw-8-2024/challenges/challenge-4388/copy-from/1386326765

bool canDrive(vector<pair<pair<int, int>, int>>& groups, int capacity)
{
    int currCapacity=0;
    
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    sort(groups.begin(), groups.end());
    
    for(size_t i = 0; i < groups.size(); i++)
    {
        while(!pq.empty() && pq.top().first <= groups[i].first.first)
        {
            currCapacity -= pq.top().second;
            pq.pop();
        }
        
        pq.push({groups[i].first.second, groups[i].second});
        currCapacity+=groups[i].second;
        
        if(currCapacity>capacity)
        {
            return false;
        }
    }
    
    return true;
}

int main() 
{
    int q = 0;
    cin >> q;
    
    while(q--)
    {
        int n = 0, c = 0;
        cin>>n>>c;
        
        vector<pair<pair<int, int>, int>> groups;
        
        for(int i = 0; i < n; i++)
        {
            int p = 0, a = 0, l = 0;
            cin>>p>>a>>l;
            
            groups.push_back({{a, l}, p});
        }
        
        cout<<canDrive(groups, c)<<'\n';
    }
    return 0;
}
