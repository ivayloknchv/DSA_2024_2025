// https://leetcode.com/problems/count-nice-pairs-in-an-array/description/?envType=problem-list-v2&envId=hash-table

class Solution {
public:

    int rev(int num)
    {
        int res=0;
        while(num!=0)
        {
            res*=10;
            res+=num%10;
            num/=10;
        }

        return res;
    }

    int countNicePairs(vector<int>& nums) 
    {
        const int mod = 1e9+7;
        int ans=0;
        unordered_map<int, long long> m;

        for(int i = 0; i < nums.size(); i++)
        {
            int curr = (nums[i] - rev(nums[i])) % mod;
            m[curr]++;
            m[curr]%=mod;
        }

        for (auto& it : m) 
        {
            long long count = (it.second * (it.second - 1) / 2) % mod; 
            ans = (ans + count) % mod; 
        }

        return ans;
    }
};
