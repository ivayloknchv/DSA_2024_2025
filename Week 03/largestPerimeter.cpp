// https://leetcode.com/problems/largest-perimeter-triangle/description/?envType=problem-list-v2&envId=an1ryio3

class Solution {
public:
    int largestPerimeter(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());

        reverse(nums.begin(), nums.end());

        for(int i=0;i<nums.size()-2;i++)
        {
            if(nums[i]<nums[i+1]+nums[i+2])
            {
                return nums[i]+nums[i+1]+nums[i+2];
            }
        }

        return 0;
    }
};
