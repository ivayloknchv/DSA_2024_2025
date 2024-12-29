#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;


int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N = 0;
    cin>>N;
    vector<int> nums(N);
    
    for(int i = 0; i < N; i++)
    {
        cin>>nums[i];
    }
    
    unordered_set<int> current;
    int maxSize=0;
    int leftMost=0;
    
    for(int i = 0; i < N; i++)
    {
        if(current.count(nums[i]))
        {
            while(!current.empty() && current.count(nums[i]))
            {
                current.erase(nums[leftMost++]);
            }
        }
        
        current.insert(nums[i]);
        maxSize=max(maxSize, (int)current.size());
    }
    
    cout<<maxSize;
    return 0;
}
