#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// https://www.hackerrank.com/contests/sda-hw-8-2022/challenges/fullstack-developer/problem

struct Task
{
    int beg = 0, duration = 0, idx = 0;
    
    Task(int beg, int duration, int idx) : beg(beg), duration(duration), idx(idx)
    {}
};

struct CmpBeg
{
    bool operator()(const Task& lhs, const Task& rhs)
    {
        return lhs.beg>rhs.beg;
    }
};

struct CmpDuration
{
    bool operator()(const Task& lhs, const Task& rhs)
    {
        if(lhs.duration == rhs.duration)
        {
            return lhs.idx > rhs.idx;
        }
        return lhs.duration>rhs.duration;
    }
};

int main() 
{
    int N = 0;   
    cin>>N;
    priority_queue<Task, vector<Task>, CmpBeg> pqBeg;
    priority_queue<Task, vector<Task>, CmpDuration> pqReady;
    
    for(int i = 0; i < N; i++)
    {
        int beg = 0, dur = 0;
        cin>>beg>>dur;
        
        pqBeg.push({beg, dur, i});
    }
    
    int currTime=0;
    
    while(!pqBeg.empty() || !pqReady.empty())
    {
        while(!pqBeg.empty() && pqBeg.top().beg <= currTime)
        {
            pqReady.push(pqBeg.top());
            pqBeg.pop();
        }
        
        if(!pqReady.empty())
        {
            currTime = currTime + pqReady.top().duration;
            cout<<pqReady.top().idx<<' ';
            pqReady.pop();
            
        }
        else if(!pqBeg.empty())
        {
            currTime = pqBeg.top().beg;
        }
    }
    
    return 0;
}
