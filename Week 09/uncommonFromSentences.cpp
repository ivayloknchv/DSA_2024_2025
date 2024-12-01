// https://leetcode.com/problems/uncommon-words-from-two-sentences/description/?envType=problem-list-v2&envId=hash-table 

class Solution 
{
public:
    vector<string> uncommonFromSentences(string s1, string s2) 
    {
        stringstream ss1(s1);

        unordered_map<string, int> m1;
        unordered_map<string, int> m2;

        while(!ss1.eof())
        {
            string word;
            ss1>>word;
            m1[word]++;
        }

        stringstream ss2(s2);

        while(!ss2.eof())
        {
            string word;
            ss2>>word;
            m2[word]++;
        }

        vector<string> ans;

        for(auto& it : m1)
        {
            if(it.second==1 && m2.find(it.first)==m2.end())
            {
                ans.push_back(it.first);
            }
        }

        for(auto& it : m2)
        {
            if(it.second==1 && m1.find(it.first)==m1.end())
            {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};
