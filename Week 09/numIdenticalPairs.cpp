// https://leetcode.com/problems/number-of-good-pairs/description/?envType=problem-list-v2&envId=hash-table

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) 
    {
        int counter=0;
        unordered_map<int, int> m;

        for(int n : nums)
        {
            if(m.find(n) != m.end())
            {
                counter+=m[n];
            }
            m[n]++;
        } 

        return counter;
    }
};
