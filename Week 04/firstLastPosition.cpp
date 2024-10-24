// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/?envType=problem-list-v2&envId=binary-search

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        auto lower = lower_bound(nums.begin(), nums.end(), target);
        auto upper = upper_bound(nums.begin(), nums.end(), target);

        if(lower!=upper)
        {
            vector<int> res(2);
            res[0]=lower-nums.begin();
            res[1]=upper-nums.begin()-1;

            return res;
        }   

        return {-1,-1};
    }
};
