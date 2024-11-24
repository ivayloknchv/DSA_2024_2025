// https://leetcode.com/problems/jump-game-ii/

class Solution {
public:
    int jump(vector<int>& nums) 
    {
        vector<int> dp(nums.size(), INT_MAX);
        dp[0] = 0;

        for(int i = 1; i <nums.size(); i++)
        {
            int steps = INT_MAX;

            for(int j = 0; j < i; j++)
            {
                if(j+nums[j]>=i)
                {
                    steps=min(steps, 1 + dp[j]);
                }
            }
            dp[i]=steps;
        }    

        return dp.back();
    }
};
