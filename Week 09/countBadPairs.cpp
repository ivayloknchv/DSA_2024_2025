class Solution {
public:
    long long countBadPairs(vector<int>& nums) 
    {
        unordered_map<int, int> m;
        long long all = nums.size()*(nums.size()-1)/2;
        long long good=0;

        for(int i = 0; i<nums.size(); i++)
        {
            good+=m[nums[i]-i];
            m[nums[i]-i]++;
        }    

        return all - good;
    }
};
