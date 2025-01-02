#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main() 
{   
    int n = 0, t = 0;
    cin>>n;
    
    vector<pair<pair<int, int>, int>> intervals(n);
    
    for(int i = 0; i < n; i++)
    {
        int beg = 0, end = 0;
        cin>>beg>>end;
        intervals[i] = {{beg, end}, i};
    }
    
    cin>>t;
    
    sort(intervals.begin(), intervals.end());
    
    priority_queue<int, vector<int>, greater<>> seats;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    
    for(int i = 0; i < n; i++)
    {
        seats.push(i);
    }
    
    for(int i = 0; i < n; i++)
    {
        while(!pq.empty() && intervals[i].first.first >= pq.top().first)
        {
            int s = pq.top().second;
            pq.pop();
            seats.push(s);
        }
        
        if(intervals[i].second == t)
        {
            cout<<seats.top();
            return 0;
        }
        
        pq.push({intervals[i].first.second, seats.top()});
        seats.pop();
    }
    
    return 0;
}
