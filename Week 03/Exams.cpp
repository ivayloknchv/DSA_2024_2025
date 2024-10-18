#include <iostream>
#include <string>
#include <vector>

using namespace std;

// https://www.hackerrank.com/contests/sda-2021-2021-test-1/challenges/challenge-3098/problem

int main()
{
    bool nums[70001]{};
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n=0;
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        nums[num]=true;
    }
    
    for(int i=0;i<70001;i++)
    {
        if(nums[i])
        {
            cout<<i<<' ';
        }
    }
    
    return 0;
}
