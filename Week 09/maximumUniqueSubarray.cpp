// https://leetcode.com/problems/maximum-erasure-value/description/

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        unordered_map<int, int> m;
        int maxSum=0;
        int currSum =0;
        int leftIdx=0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(m.find(nums[i])!=m.end())
            {
                int idx = m[nums[i]];

                while(leftIdx<=idx)
                {
                    currSum-=nums[leftIdx++];
                }
            }

            m[nums[i]]=i;
            currSum+=nums[i];
            maxSum=max(maxSum, currSum);
        }    

        return maxSum;
    }
};
