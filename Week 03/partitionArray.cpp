// https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/description/?envType=problem-list-v2&envId=an1rjax7

class Solution {
public:
   int partitionArray(vector<int>& nums, int k) {

    sort(nums.begin(), nums.end());

    int startSeq = 0;
    int endSeq = 0;
    int counter = 0;

    while (endSeq < nums.size())
    {
        while ((endSeq < nums.size()) && (nums[endSeq] - nums[startSeq]) <= k)
        {
            ++endSeq;
        }
        counter++;
        startSeq = endSeq;
    }

    return counter;
}
};
