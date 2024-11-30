// https://leetcode.com/problems/coin-change-ii/description/

class Solution {
public:
    int change(int amount, vector<int>& coins) 
    {
        vector<vector<uint64_t>>dp(coins.size()+1, vector<uint64_t>(amount+1));

        for(uint64_t i = 0; i <=coins.size(); i++)
        {
            dp[i][0]=1;
        }

        for(uint64_t i = 1; i <= coins.size(); i++)
        {
            for(uint64_t j = 1; j <= amount; j++)
            {
                dp[i][j]+=dp[i-1][j];

                if(j >= coins[i - 1]) 
                {
                    dp[i][j] += dp[i][j - coins[i - 1]];
                }
            }
        }

        return dp[coins.size()][amount];

    }
};
