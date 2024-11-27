// https://leetcode.com/problems/isomorphic-strings/submissions/1464382760/

class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        if(s.size()!=t.size())
        {
            return false;
        }

        map<char,int> m1;
        map<char, int> m2;

        for(int i = 0; i<s.size(); i++)
        {
            if(m1[s[i]]!=m2[t[i]])
            {
                return false;
            }
            else
            {
                m1[s[i]]=i+1;
                m2[t[i]]=i+1;
            }
        }

        return true;
    }
};
