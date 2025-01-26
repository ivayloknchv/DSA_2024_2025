#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n = 0;
    cin>>n;
    
    vector<int> I;
    vector<int> B;
    
    for(int i = 0; i < n; i++)
    {
        int num = 0;
        cin>>num;
        I.push_back(num);
    }
    
    
    for(int i = 0; i < n; i++)
    {
        int num = 0;
        cin>>num;
        B.push_back(num);
    }
    
    
    unordered_map<int, int> stickers;
    
    int counter = 0;
    
    for(int i = 0; i < n; i++)
    {
        stickers[I[i]]++;
        
        if(stickers.find(B[i])==stickers.end())
        {
            counter++;
        }
        else
        {
            stickers[B[i]]--;
            
            if(stickers[B[i]] == 0)
            {
                stickers.erase(B[i]);
            }
        }
    }
    
    cout<<counter;
    
    return 0;
}
