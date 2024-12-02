// https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/description/?envType=problem-list-v2&envId=hash-table

class Solution {
public:

    bool check(const vector<int>& counter, const string& s)
    {
        vector<int> curr(26);

        for(char ch : s)
        {
            curr[ch-'a']++;
        }

        for(int i = 0; i < 26; i++)
        {
            if (curr[i]>counter[i])
            {
                return false;
            }
        }

        return true;
    }

    int countCharacters(vector<string>& words, string chars) 
    {
        vector<int> counter(26);

        for(char ch : chars)
        {
            counter[ch-'a']++;
        }

        int ans = 0;

        for(string& word : words)
        {
            if(check(counter, word))
            {
                ans+=word.size();
            }
        }

        return ans;
    }
};
