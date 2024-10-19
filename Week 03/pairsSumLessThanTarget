// https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/description/?envType=problem-list-v2&envId=awdeugtv

class Solution {
public:
    int countPairs(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());

        int counter=0;

        int left=0;
        int right=nums.size()-1;

        while(left<=right)
        {
            if(nums[left]+nums[right]<target)
            {
                counter+=right-left;
                left++;
            }
            else
            {
                right--;
            }
        }    

        return counter;
    }
};
