#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

// https://www.hackerrank.com/contests/sda-2021-2022-test5-8dec/challenges/challenge-3156/problem

int main() 
{
    int n = 0;
    cin>>n;
    unordered_map<string, int>m;
    
    vector<string> strings(n);
    
    for(int i = 0; i < n; i++)
    {
        cin>>strings[i];
        m[strings[i]]++;
    }
    
    for(string s : strings)
    {
        cout<<m[s]<<' ';
    }
    return 0;
}
