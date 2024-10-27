// https://leetcode.com/problems/minimum-size-subarray-sum/description/?envType=problem-list-v2&envId=amgo332d

class Solution 
{
public:

bool check(const vector<long long>& sum, int test, long long target)
{
    for (int i = 0; i < sum.size() - test + 1; i++)
    {
        long long rightSum = sum[i + test - 1];
        long long leftSum = 0;

        if (i-1 >= 0)
        {
            leftSum = sum[i-1];
        }

        if (rightSum - leftSum >= target)
        {
            return true;
        }
    }

    return false;
}

int minSubArrayLen(int target, vector<int>& nums)
{
    int l = 1;
    int r = nums.size();

    int ans = INT_MAX;

    vector<long long>accumulatedSum(nums.size());
    accumulatedSum[0] = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        accumulatedSum[i] = nums[i] + accumulatedSum[i - 1];
    }

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (check(accumulatedSum, mid, target))
        {
            ans = min(ans, mid);
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return (ans == INT_MAX) ? 0 : ans;
}
};
