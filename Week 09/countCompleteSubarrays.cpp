// https://leetcode.com/problems/count-complete-subarrays-in-an-array/

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) 
    {
        unordered_set<int> tmp;

        for(int n : nums)
        {
            tmp.insert(n);
        }    

        int disticintCount=tmp.size();
        int ans=0;

        for(int i = 0; i < nums.size(); i++)
        {
            unordered_set<int> curr;

            for(int j = i; j < nums.size(); j++)
            {
                curr.insert(nums[j]);

                if(curr.size()==disticintCount)
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};
