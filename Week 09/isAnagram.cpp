// https://leetcode.com/problems/valid-anagram/?envType=study-plan-v2&envId=top-interview-150

class Solution 
{
public:
    bool isAnagram(string s, string t) 
    {
        unordered_map<char, int> m;

        for(char ch : s)
        {
            m[ch]++;
        }

        for(char ch : t)
        {
            m[ch]--;
        }

        for(auto& it : m)
        {
            if(it.second!=0)
            {
                return false;
            }
        }
        return true;    
    }
};
