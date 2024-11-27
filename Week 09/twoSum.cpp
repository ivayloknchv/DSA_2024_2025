// https://leetcode.com/problems/two-sum/description/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> m;

        for(int i = 0; i<nums.size(); i++)
        {
            auto iter = m.find(nums[i]);

            if(iter!=m.end())
            {
                vector<int> ans;
                ans.push_back(i);
                ans.push_back(iter->second);
                return ans;
            }
             m[target-nums[i]]=i;
        }

        vector<int> r;

        return r;
    }
};
