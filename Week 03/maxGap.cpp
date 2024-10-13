// https://leetcode.com/problems/maximum-gap/description/?envType=problem-list-v2&envId=an1phfb2

class Solution {
public:

int maximumGap(vector<int>& nums)
{
    if(nums.size()<2)
    {
        return 0;
    }
    sort(nums.begin(), nums.end());

    int max=nums[1]-nums[0];

    for(int i=0; i< nums.size()-1; i++)
    {
        int curr=nums[i+1]-nums[i];

        if(curr>max)
        {
            max=curr;
        }
    }

    return max;
}
};
