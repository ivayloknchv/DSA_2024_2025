// https://leetcode.com/problems/subarray-sum-equals-k/description/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        if(nums.size()==0)
        {
            return 0;
        }

        int ans = 0;

        vector<int> prefSum(nums.size());

        prefSum[0]=nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            prefSum[i] = nums[i] + prefSum[i-1];
        }

        unordered_map<int, int> m; // complements->count
        m[0]=1;
        for(int i = 0; i < prefSum.size(); i++)
        {
            auto it = m.find(prefSum[i]-k);

            if(it!=m.end())
            {
                ans+=m[prefSum[i]-k];
            }

            m[prefSum[i]]++;
        }

        return ans;

        
    }
};
