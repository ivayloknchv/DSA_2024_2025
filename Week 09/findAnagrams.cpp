// https://leetcode.com/problems/find-all-anagrams-in-a-string/description/?envType=problem-list-v2&envId=amgo332d

class Solution 
{
   int counterWindow[26]{};
   int counterWord[26]{};

    bool check()
    {
        for(int i = 0; i <26; i++){
            if(counterWindow[i]!=counterWord[i])
            {
                return false;
            }
        }

        return true;
    }
    

public:
    vector<int> findAnagrams(string s, string p) 
    {
        if(s.size() < p.size())
        {
            return {};
        }

        vector<int> ans;

        for(char ch : p)
        {
           counterWord[ch-'a']++;
        }

        for(int i = 0; i < p.size(); i++)
        {
            counterWindow[s[i] - 'a']++;
        }

        if(check())
        {
            ans.push_back(0);
        }

        for(int i = 1; i < s.size()-p.size()+1; i++)
        {
            counterWindow[s[i-1]-'a']--;

            counterWindow[s[i+p.size()-1]-'a']++;

            if(check())
            {
                ans.push_back(i);
            }
        }

        return ans;

    }
};
