#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
// https://www.hackerrank.com/contests/sda-hw-8-2024/challenges/two-pqs/problem

int main() 
{
    int n=0;
    cin>>n;
    vector<pair<pair<int,int>, int>> guests;
    
    for(int i = 0; i < n; i++)
    {
        int a = 0, l = 0;
        cin>>a>>l;
        
        guests.push_back({{a,l}, i});
    }
    
    int target=0;
    cin>>target;
    
    sort(guests.begin(), guests.end());
    
    priority_queue<int, vector<int>, greater<int>> allSeats;
    
    for(int i = 0; i < n; i++)
    {
        allSeats.push(i);
    }
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> currentGuests;
    
    for(int i = 0; i < n; i++)
    {
        while(!currentGuests.empty() && currentGuests.top().first <= guests[i].first.first)
        {
            allSeats.push(currentGuests.top().second);
            currentGuests.pop();
        }
        
        if(guests[i].second == target)
        {
            cout<<allSeats.top();
            return 0;
        }
        currentGuests.push({guests[i].first.second, allSeats.top()});
        allSeats.pop();
    }
    
    
    return 0;
}
