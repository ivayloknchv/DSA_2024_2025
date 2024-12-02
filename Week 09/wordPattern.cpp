// https://leetcode.com/problems/word-pattern/description/?envType=problem-list-v2&envId=amgo332d

class Solution {
public:
    bool wordPattern(string pattern, string s) 
    {
        vector<string> words;

        stringstream ss(s);

        unordered_map<string, char> m1;
        unordered_map<char, string> m2;

        while(!ss.eof())
        {
            string curr;
            ss>>curr;
            words.push_back(curr);
        }

        if(words.size()!=pattern.size())
        {
            return false;
        }

        for(int i = 0; i < pattern.size(); i++)
        {
            if(m1.find(words[i])==m1.end() && m2.find(pattern[i]) == m2.end())
            {
                m1[words[i]]=pattern[i];
                m2[pattern[i]]=words[i];
            }
            if(m1[words[i]] != pattern[i] || m2[pattern[i]] != words[i])
            {
                return false;
            }
        }

        return true;
    }
};
