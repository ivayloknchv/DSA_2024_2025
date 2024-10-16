// https://leetcode.com/problems/rearrange-array-to-maximize-prefix-score/?envType=problem-list-v2&envId=awdekmvh

class Solution {
public:
    int maxScore(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());

        vector<long long> prefix(nums.size());

        prefix[0]=nums[0];

        for(int i = 1; i<nums.size(); i++)
        {
            prefix[i]=nums[i]+prefix[i-1];
        }    

        int counter=0;

        for(int i=0;i<prefix.size();i++)
        {
            if(prefix[i]>0)
            {
                counter++;
            }
            else
            {
                break;
            }
        }

        return counter;
    }
};
