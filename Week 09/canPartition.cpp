// https://leetcode.com/problems/partition-equal-subset-sum/description/?envType=problem-list-v2&envId=dynamic-programming

class Solution 
{
public:
    bool canPartition(vector<int>& nums) 
    {
        int sum = 0;

        for(int n : nums)
        {
            sum+=n;
        }

        if(sum%2==1)
        {
            return false;
        }

        sum/=2;

        vector<vector<bool>> dp(nums.size()+1, vector<bool>(sum+1, false));

        for(int i = 0; i <= nums.size(); i++)
        {
            dp[i][0]=true;
        }

        for(int i = 1; i <= nums.size(); i++)
        {
            for(int j = 1; j <= sum; j++)
            {
                bool notAdd = dp[i-1][j];

                bool add = false;

                if(j-nums[i-1]>=0)
                {
                    add = dp[i-1][j-nums[i-1]];
                }

                dp[i][j] = add || notAdd;
            }
        }

        return dp[nums.size()][sum];
    }
};
