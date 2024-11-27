#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <set>
using namespace std;

// https://www.hackerrank.com/contests/sda-hw-7-2024/challenges/challenge-4337/problem

int main() 
{  
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> v1;
    vector<int> v2;
    
    int N=0, M = 0;
    cin>>N>>M;
    
    for(int i = 0; i < M; i++)
    {
        int num = 0;
        cin>>num;
        
        v1.push_back(num);
    }
    
    unordered_set<int> s;
    
    for(int n:v1)
    {
        s.insert(n);
    }
    
    for(int i = 1; i <= N; i++)
    {
        if(s.find(i)==s.end())
        {
            v2.push_back(i);
        }
    }
    
    auto iter1=v1.begin();
    auto iter2=v2.begin();
    
    while(iter1!=v1.end() && iter2!=v2.end())
    {
        if(*iter1<*iter2)
        {
            cout<<*iter1<<' ';
            iter1++;
        }
        else
        {
            cout<<*iter2<<' ';
            iter2++;
        }
    }
    
    while(iter1!=v1.end())
    {
        cout<<*iter1<<' ';
        iter1++;
    }
    
    while(iter2!=v2.end())
    {
        cout<<*iter2<<' ';
        iter2++;
    }
    return 0;
}
