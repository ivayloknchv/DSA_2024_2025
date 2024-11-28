class Solution {
public:
    int repeatedNTimes(vector<int>& nums) 
    {
        unordered_map<int, int> m;

        for(int n : nums)
        {
            m[n]++;

            if(m[n]>1)
            {
                return n;
            }
        }   

        return -1;
    }
};
