// https://leetcode.com/problems/house-robber/description/

class Solution {
public:
    int rob(vector<int>& nums) 
    {
        if(nums.size()==1)
        {
            return nums[0];
        }
        
        vector<int> memo(nums.size());
        memo[0]=nums[0];
        memo[1]=nums[1];

        int maxEl=memo[0];

        for(int i = 2; i < nums.size(); i++)
        {
            memo[i]=nums[i]+maxEl;
            maxEl=max(maxEl, memo[i-1]);
        }

        return *max_element(memo.begin(), memo.end());
    }
};
