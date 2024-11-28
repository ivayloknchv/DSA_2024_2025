// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_map<char, int> m;
        int maxSize=0;
        int startIdx=0;

        for(int i = 0; i < s.size(); i++)
        {
            if(m.find(s[i])!=m.end() && m[s[i]] >= startIdx)
            {
                startIdx=m[s[i]] + 1;
            }

            m[s[i]]=i;
            maxSize=max(maxSize,i-startIdx+1);
        }

        return maxSize;
    }
};
