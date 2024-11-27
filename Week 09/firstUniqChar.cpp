// https://leetcode.com/problems/first-unique-character-in-a-string/description/?source=submission-ac

class Solution {
public:
    int firstUniqChar(string s) 
    {
           map<char, int> m;

           for(int i = 0; i <s.size(); i++)
           {
                m[s[i]]++;
           }

           for(int i = 0; i <s.size(); i++)
           {
                if(m[s[i]]==1)
                {
                    return i;
                }
           }

           return -1;
            
    }
};
