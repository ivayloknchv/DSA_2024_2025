// https://leetcode.com/problems/minimum-average-of-smallest-and-largest-elements/description/?envType=problem-list-v2&envId=an1rjax7
class Solution {
public:
    double minimumAverage(vector<int>& nums) 
    {
        vector<double> averages;
        sort(nums.begin(), nums.end());
        int l=0;
        int r=nums.size()-1;

        while(l<=r)
        {
            averages.push_back((nums[l]+nums[r])/2.00);
            l++;
            r--;
        }

        double ans=averages[0];

        for(int i=1;i<averages.size();i++)
        {
            if(ans>averages[i])
            {
                ans=averages[i];
            }
        }

        return ans;
    }   
};
