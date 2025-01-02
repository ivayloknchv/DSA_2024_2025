#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


int main() 
{   
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n = 0;
    cin>>n;
    
    vector<int> days(n);
    
    for(int i = 0; i < n; i++)
    {
        cin>>days[i];
    }
    
    int counter = 0;
    
    multiset<int> ms;
    
    for(int i = 0; i < n; i++)
    {
        ms.insert(days[i]);
        
        int curr = 0;
        cin>>curr;
        
        auto it = ms.find(curr);
        
        if(it!=ms.end())
        {
            ms.erase(it);
        }
        else
        {
            counter++;
        }
    }
    cout<<counter;
    return 0;
}
