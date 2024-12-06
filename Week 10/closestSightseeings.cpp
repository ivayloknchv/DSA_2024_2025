#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// https://www.hackerrank.com/contests/sda-hw-8-2024/challenges/--164/problem

struct Coordinates
{
    long long x = 0;
    long long y = 0;
    long long dist = 0;
    
    Coordinates()=default;
    Coordinates(long long x, long long y, long long dist) : x(x), y(y), dist(dist)
    {}
    
};

struct MyCmp
{
    
  bool operator()(const Coordinates& lhs, const Coordinates& rhs)
  {
      if(lhs.dist == rhs.dist)
      {
          if(lhs.x==rhs.x)
          {
              return lhs.y<rhs.y;
          }
          return lhs.x<rhs.x;
      }
      return lhs.dist<rhs.dist;
  }
};

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long x = 0, y = 0, N = 0, K = 0;
    
    cin>>x>>y>>N>>K;
    
    vector<Coordinates> vec;
    
    for(int i = 0; i < N; i++)
    {
        long long currX = 0, currY = 0;
        cin>>currX>>currY;
        long long dist = pow(x-currX, 2) + pow(y-currY, 2);
        
        Coordinates temp(currX, currY, dist);
        
        vec.push_back(temp);
    }
    
    priority_queue<Coordinates, vector<Coordinates>, MyCmp> pq;
    
    MyCmp comp;
    
    for(int i = 0; i < K; i++)
    {
        pq.push(vec[i]);
    }
    
    for(int i = K; i < N; i++)
    {
        if(comp(vec[i], pq.top()))
        {
            pq.pop();
            pq.push(vec[i]);
        }
    }
           
           
    vector<Coordinates> res;
    
    while(!pq.empty())
    {
        res.push_back(pq.top());
        pq.pop();
    }
    
    reverse(res.begin(), res.end());
           
    for(auto&it : res)
    {
        cout<<it.x<<' '<<it.y<<'\n';
    }
    return 0;
}
