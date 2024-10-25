// https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/description/?envType=problem-list-v2&envId=binary-search

class Solution {
public:

    int checker(const vector<int>& nums, int target)
    {
        int counter = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i]>=target)
            {
                counter++;
            }
        }

        return counter;
    } 

    int specialArray(vector<int>& nums) 
    {
        int l = 0;
        int r = nums.size();

        while(l <= r)
        {
            int mid = l + (r - l) / 2;

            int res=checker(nums, mid);

            if(res==mid)
            {
                return res;
            }
            else if(res<mid)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }   
        return -1;
    }
};
