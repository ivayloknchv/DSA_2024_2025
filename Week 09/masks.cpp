#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

// https://www.hackerrank.com/contests/sda-hw-7-2022/challenges/zoros-mask/problem

int main() 
{
    unordered_set<int> res;
    
    int N = 0;
    cin>>N;
    
    for(int i = 0; i < N; i++)
    {
        int num = 0;
        cin>>num;
        
        for(int j = 0; j <= num; j++)
        {
            if((num | j) ==num)
            {
                res.insert(j);
            }
        }
    }
    
    cout<<res.size();
    return 0;
}
