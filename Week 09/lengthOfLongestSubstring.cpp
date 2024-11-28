// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string str) 
    {
        unordered_set<char> s;
        int maxLen=0;
        int leftmost=0;

        for(int i = 0; i < str.size(); i++)
        {

            if(s.find(str[i])!=s.end())
            {
                while(s.find(str[i])!=s.end())
                {
                    s.erase(str[leftmost++]);
                }
            }
            s.insert(str[i]);
            maxLen=max(maxLen, (int)s.size());
        }
        return maxLen;
    }
};
