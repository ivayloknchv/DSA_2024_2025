// https://leetcode.com/problems/longest-increasing-subsequence/description/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        vector<int> lis(nums.size(), 0);

        lis[0]=1;

        for(int i = 0; i < nums.size(); i++)
        {
            int maxVal=0;

            for(int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    maxVal=max(maxVal, lis[j]);
                }
            }
            lis[i] = 1+maxVal;
        }

        return *max_element(lis.begin(), lis.end());   
    }
};
