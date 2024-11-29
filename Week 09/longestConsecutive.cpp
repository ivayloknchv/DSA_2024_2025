https://leetcode.com/problems/longest-consecutive-sequence/description/?source=submission-ac
class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int> s;
        int currSize=0;
        int maxSize=0;

        for(int n : nums)
        {
            s.insert(n);
        }

        for(int n : nums)
        {
            if(s.find(n-1)==s.end())
            {
                currSize=0;
                int iter = n;
                while(s.find(iter++)!=s.end())
                {
                    currSize++;
                }
            }

            maxSize=max(maxSize, currSize);
        }

        return maxSize;
    }
};
