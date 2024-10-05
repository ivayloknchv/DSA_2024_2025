#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,k;
    cin>>n>>k;
    vector<int> nums;
    
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }
    
    sort(nums.begin(), nums.end());
    
    int min=nums[k-1]-nums[0];
    for(int i=0;i<n-k + 1;i++)
    {
        int current=num[i+k-1]+nums[i];
        if(current<min)
        {
            min=current;
        }
    }
    
    cout<<min;
    return 0;
}
