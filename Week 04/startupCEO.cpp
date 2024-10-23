#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// https://www.hackerrank.com/contests/sda-24-25-2/challenges/challenge-3670/problem

bool check(const vector<long long>& skills, long long target, long long teamsCount)
{
    long long currentSkillsSum=0;
    long long teamsCounter=1;
    
    for(size_t i = 0; i<skills.size(); i++)
    {
        if(skills[i]>target)
        {
            return false;
        }
        
        currentSkillsSum+=skills[i];
        
        if(currentSkillsSum>target)
        {
            teamsCounter++;
            currentSkillsSum=skills[i];
        }
    }
    
    return teamsCounter <= teamsCount;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long N, T;
    cin>>N>>T;
    long long max=0;
    long long sum=0;
    vector<long long> skills(N);
    
    for(long long i = 0; i < N; i++)
    {
        cin>>skills[i];
        sum+=skills[i];
        
        if(skills[i]>max)
        {
            max=skills[i];
        }
    }
    
    long long l = max;
    long long r=sum;
    long long result=0;
    
    while(l<=r)
    {
        long long mid = l + (r-l)/2;
        
        if(check(skills,mid,T))
        {
            result=mid;
            r=mid-1;
        }
        
        else
        {
            l = mid+1;
        }
    }
    
    cout<<result;
    
    return 0;
}
