#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

// https://www.hackerrank.com/contests/sda-hw-6-2024/challenges/exam-7/problem

int main() 
{
    string str;
    cin>>str;
    vector<int> dp(str.size()+1, INT_MAX);
    dp[0]=0;
    
    for(size_t i=0 ; i < str.size()-1; i++)
    {
        if(dp[i]==INT_MAX)
        {
            continue;
        }
        
        int letters[26]{};
        
        for(size_t j = i; j <str.size(); j++)
        {
            letters[str[j]-'a']++;
            bool flag = true;
            for(int k = 0; k < 26; k++)
            {
                if(letters[k]!=0)
                {
                    if(letters[k]%2==0)
                    {
                        flag=false;
                        break;
                    }
                }
            }
            
            if(flag)
            {
               dp[j+1]=min(dp[j+1], dp[i]+1);
            }
        }
    }
    
    cout<<dp[str.size()];
    return 0;
}
