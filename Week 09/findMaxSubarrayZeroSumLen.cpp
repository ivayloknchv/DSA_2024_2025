// https://www.geeksforgeeks.org/find-the-largest-subarray-with-0-sum/

int findMaxSubarrayZeroSumLen(const vector<int>& nums)
{
    if (nums.size() == 0)
    {
        return 0;
    }
    vector<int> prefixSum(nums.size());

    prefixSum[0] = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        prefixSum[i] = nums[i] + prefixSum[i - 1];
    }

    unordered_map<int, int> m; // nums -> first occurance

    int ans = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (m.find(prefixSum[i]) == m.end())
        {
            m[prefixSum[i]] = i;
        }
        else
        {
            ans = max(ans, i - m[prefixSum[i]]);
        }
    }

    return ans; 
}
