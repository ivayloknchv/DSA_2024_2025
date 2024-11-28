// https://www.hackerrank.com/contests/sda-test5-2022-2023-43wdst52/challenges/dundee-the-crocodile/submissions/code/1385984341

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main() 
{
    string str;
    unordered_map<string, int> m;
    
    while(cin>>str)
    {
        m[str]++;
    }
    
    vector<string> v;
    for(auto& it : m)
    {
        if(it.second==1)
        {
            v.push_back(it.first);
        }
    }
    
    sort(v.begin(), v.end());
    
    for(auto s : v)
    {
        cout<<s<<'\n';
    }
    return 0;
}
