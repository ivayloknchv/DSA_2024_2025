#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

// https://www.hackerrank.com/contests/5-2023-2024/challenges/challenge-4497/problem

int main() 
{
    int t=0;
    cin>>t;
    
    while(t--)
    {
        int l1=0, l2=0;
        cin>>l1>>l2;
        bool isValid=true;
        unordered_map<string, int> mp1;
        unordered_map<string, int> mp2;
        
        for(int i = 0; i < l1; i++)
        {
            string s;
            cin>>s;
            mp1[s]++;
        }
        
        for(int i = 0; i < l2; i++)
        {
            string s;
            cin>>s;
            mp2[s]++;
        }
        

        for(auto& it : mp2)
        {
            if(it.second > mp1[it.first])
            {
                isValid=false;
                break;
            }
        }
        
        if(isValid)
        {
            cout<<"Yes\n";
        }
        else
        {
            cout<<"No\n";
        }
    }
    return 0;
}
