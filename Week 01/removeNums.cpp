#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n,k;
    cin>>n>>k;
    
    vector<int> nums;
    
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        
        if(temp!=k)
        {
            nums.push_back(temp);
        }
    }
    
    for(size_t i=0;i<nums.size(); i++)
    {
        cout<<nums[i]<<' ';
    }
    return 0;
}

