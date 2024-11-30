#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

// https://www.hackerrank.com/contests/sda-test-5/challenges/1-140/problem

int main() {
    int N = 0;
    cin>>N;
    
    int delivered=0;
    
    unordered_map<int, int> mp;
    
    for(int i = 0; i < N; i++)
    {
        int num=0;
        cin>>num;
        
        mp[num]++;
        
        if(mp[num]==10)
        {
            delivered++;
            mp.erase(num);
        }
    }
    
    
    int ppl=0;
    int products=0;
    for(auto& it : mp)
    {
        products+=it.second;    
        ppl++;
    }
    
    cout<<ppl<<' '<<products;
    
    return 0;
}
