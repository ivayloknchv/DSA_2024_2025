#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    unordered_map<string, int> mp;
    
    int n = 0, m = 0;
    cin>>n>>m;
    
    for(int i = 0; i < n; i++)
    {
        string curr;
        
        for(int j = 0; j < m; j++)
        {
            int d = 0;
            cin>>d;
            curr+= to_string(d);
        }
        
        mp[curr]++;
    }
    
    int res = 0;
    
    for(auto& it : mp)
    {
        if(it.second==1)
        {
            res++;
        }
    }
    
    cout<<res;
    
    
    
    return 0;
}
