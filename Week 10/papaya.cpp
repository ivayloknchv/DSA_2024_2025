#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// https://www.hackerrank.com/contests/sda-20232024-test-4/challenges/challenge-4446/problem

int main()
{
    priority_queue <long long, vector<long long>, greater<long long> > pq;
    
    long long N = 0, S = 0;
    
    cin>>N>>S;
    
    for(int i = 0; i < N; i++)
    {
        int num = 0;
        cin>>num;
        pq.push(num);
    }
    int counter = 0;
    
    while(pq.size()>1)
    {
        if(pq.top()>=S)
        {
            cout<<counter;
            return 0;
        }
        long long s1= pq.top();
        pq.pop();
        long long s2=pq.top();
        pq.pop();
        pq.push(s1+2*s2);
        counter++;
    }
    
    
    if(pq.size()==1 && pq.top()>=S)
    {
        cout<<counter;
    }
    else
    {
        cout<<-1;
    }
    return 0;
}
