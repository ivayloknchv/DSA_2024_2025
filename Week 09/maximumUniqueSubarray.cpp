// https://leetcode.com/problems/maximum-erasure-value/description/

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        set<int> s;
        int currSum=0;
        int maxSum=0;
        int leftMost=0;

        for(int i = 0; i < nums.size(); i++)
        {
            while(s.find(nums[i])!=s.end())
            {
                currSum-=nums[leftMost];
                s.erase(nums[leftMost++]);
            }

            currSum+=nums[i];
            s.insert(nums[i]);

            maxSum=max(currSum, maxSum);
        }

        return maxSum;
    }
};
