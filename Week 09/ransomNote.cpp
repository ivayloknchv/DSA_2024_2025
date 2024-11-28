// https://leetcode.com/problems/ransom-note/description/?envType=problem-list-v2&envId=hash-table

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        unordered_map<char, int> m1;
        unordered_set<char> s;
        unordered_map<char, int> m2;

        for(auto ch : ransomNote)
        {
            m1[ch]++;
            s.insert(ch);
        }

        for(auto ch : magazine)
        {
            m2[ch]++;
            s.insert(ch);
        }

        for(auto el = s.begin(); el!=s.end(); el++)
        {
            if(m1[*el]<=m2[*el])
            {
                continue;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};
