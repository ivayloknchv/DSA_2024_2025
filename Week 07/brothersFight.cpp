#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

// https://www.hackerrank.com/contests/sda-exam-20222023-part-1/challenges/challenge-3906/problem

int main() 
{
    int days = 0;
    cin>>days;
    
    vector<int> ivancho(days, 0);
    vector<int> brother(days, 0);
    
    for(int i = 0; i < days; i++)
    {
        cin>>ivancho[i];
        
    }
    for(int i = 0; i < days; i++)
    {
        cin>>brother[i];
    }
    
    int counter=0;
    map<int, int> stickers;
    
    for(int i = 0; i < days; i++)
    {
        
        
        if(stickers.find(ivancho[i])==stickers.end())
        {
            stickers.insert({ivancho[i],1});
        }
        else
        {
            stickers[ivancho[i]]++;
        }
        if(stickers.find(brother[i])==stickers.end())
        {
            counter++;
        }
        else
        {
            stickers[brother[i]]--;
            
            if(stickers[brother[i]]==0)
            {
                stickers.erase(brother[i]);
            }
        }
    }
    
    cout<<counter;
    
    return 0;
}
