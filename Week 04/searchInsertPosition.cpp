// https://leetcode.com/problems/search-insert-position/description/?envType=problem-list-v2&envId=binary-search

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        auto lower = lower_bound(nums.begin(), nums.end(), target);
        int dist=lower-nums.begin();

        return dist;
    }
};
