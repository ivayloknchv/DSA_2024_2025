#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    cin>>n;
    
    vector<int> nums;
    
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }
    
    int idx=0;
    int size=nums.size();
    int sum=0;
    while(idx<size)
    {

        while((nums[idx+1]<nums[idx]))
        {
            idx++;
        }
        sum-=nums[idx];
        
        while((nums[idx+1]>nums[idx]))
        {
            idx++;
        }
        
        sum+=nums[idx];
        idx++;
    }
    cout<<sum;
    
    return 0;
}
