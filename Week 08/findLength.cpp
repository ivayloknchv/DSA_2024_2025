// https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/

class Solution 
{
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) 
    {
        int m =nums1.size()+1;
        int n = nums2.size()+1;
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(nums1[i-1]==nums2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=0;
                }
            }
        }

        int maxEl=0;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                maxEl=max(maxEl, dp[i][j]);
            }
        }

        return maxEl;
    }
};
