https://leetcode.com/problems/counting-bits/description/?envType=problem-list-v2&envId=50vlu3z5

class Solution 
{
public:
    vector<int> countBits(int n) 
    {
        vector<int> dp(n+1);

        dp[0]=0;

        for(int i = 1; i <= n; i++)
        {
            dp[i] = dp[i/2] + i%2;
        }    

        return dp;
    }
};
