// https://leetcode.com/problems/group-anagrams/description/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string>>m;

        for(string s : strs)
        {
            string copy=s;
            sort(copy.begin(), copy.end());

            m[copy].push_back(s);
        }    

        vector<vector<string>> res;

        for(auto& it : m)
        {
            res.push_back(it.second);
        }

        return res;
    }
};
