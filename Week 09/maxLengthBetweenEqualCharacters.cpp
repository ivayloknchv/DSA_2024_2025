// https://leetcode.com/problems/largest-substring-between-two-equal-characters/description/?envType=problem-list-v2&envId=hash-table

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) 
    {
        unordered_map<char, pair<int, int>> m; // letter -> first, last idx

        for(int i = 0; i < s.size(); i++)
        {
            if(m.find(s[i])==m.end())
            {
                m[s[i]]={i,i};
            }
            else
            {
                m[s[i]].second=i;
            }
        }    

        int maxLen=-1;

        for(auto& it : m)
        {
            int curr=it.second.second-it.second.first-1;

            maxLen=max(maxLen, curr);
        }

        return maxLen;
    }
};
