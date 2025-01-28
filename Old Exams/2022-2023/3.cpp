#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


struct Person
{
    int arrive = 0;
    int leave = 0;
    int idx = 0;
};

bool operator < (const Person& lhs, const Person& rhs)
{
    if(lhs.arrive == rhs.arrive)
    {
      return lhs.leave < rhs.leave;
    }
    
    return lhs.arrive < rhs.arrive;
};

int main() 
{
    int N = 0;
    cin>>N;
    
    vector<Person> v;
    
    for(int i = 0; i < N; i++)
    {
        int arrive = 0, leave = 0;
        cin>>arrive>>leave;
        
        v.push_back({arrive, leave, i});
    }
    
    int T = 0;
    cin>>T;
    
    sort(v.begin(), v.end());
    
    priority_queue<int, vector<int>, greater<>> seats;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    
    for(int i = 0; i < N; i++)
    {
        seats.push(i);
    }
    
    for(int i = 0; i < N; i++)
    {
        while(!pq.empty() && v[i].arrive >= pq.top().first)
        {
            int seat = pq.top().second;
            pq.pop();
            seats.push(seat);
        }
        
        if(v[i].idx == T)
        {
            cout<<seats.top();
            return 0;
        }
        
        pq.push({v[i].leave, seats.top()});
        seats.pop();
    }
    
    return 0;
}
