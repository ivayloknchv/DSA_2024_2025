// https://leetcode.com/problems/squares-of-a-sorted-array/description/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        vector<int> ans(nums.size());
        int n=nums.size()-1;
        int left=0;
        int right=nums.size()-1;

        while(left<=right)
        {
            if(abs(nums[left])<abs(nums[right]))
            {
                ans[n]=(nums[right]*nums[right]);
                n--;
                right--;
            }
            else
            {
                ans[n]=(nums[left]*nums[left]);
                n--;
                left++;
            }
        }

        return ans;
    }
};
