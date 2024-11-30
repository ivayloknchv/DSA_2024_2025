// https://leetcode.com/problems/3sum/description/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());

        unordered_map<int,int> m;
        vector<vector<int>> res;

        for(int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]=i;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            int target=-nums[i];

            for(int j = i + 1; j < nums.size(); j++)
            {
                if(m.find(target-nums[j])!=m.end() && m[target-nums[j]]>j)
                {
                    res.push_back({nums[i], nums[j], target-nums[j]});
                }
                j=m[nums[j]];
            }
            i=m[nums[i]];
        }

        return res;
    }
};
