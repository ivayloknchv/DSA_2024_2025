// https://leetcode.com/problems/count-sorted-vowel-strings/description/

class Solution 
{
public:
    int countVowelStrings(int n) 
    {
        vector<int> dp(n+1);

        dp[0]=0;
        dp[1]=5;

        for(int i = 2; i <= n; i++)
        {
            dp[i]=dp[i-1]*(5+i-1)/i;
        }

        return dp[n];
    }
};
