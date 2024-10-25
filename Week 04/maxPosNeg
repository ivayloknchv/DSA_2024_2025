// https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/?envType=problem-list-v2&envId=binary-search

class Solution {
public:
    int maximumCount(vector<int>& nums) 
    {
        auto separatorNeg= upper_bound(nums.begin(), nums.end(), -1);
        int negatives = separatorNeg-nums.begin();
        
        auto separatorPos=upper_bound(nums.begin(),nums.end(), 0);
        int positives = (nums.end()-separatorPos);
        return max(positives, negatives);    
    }
};
