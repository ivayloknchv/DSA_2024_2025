// https://leetcode.com/problems/k-diff-pairs-in-an-array/description/?envType=problem-list-v2&envId=hash-table

class Solution {
public:
    int findPairs(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());

        unordered_map<int, int> m;

        for(int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]=i;
        }

        int counter = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            int complement=nums[i]-k;

            if(m.find(complement)!=m.end() && i != m[complement])
            {
                counter++;
            }

            i=m[nums[i]];
        }

        return counter;
    }
};
