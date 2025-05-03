// https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/?envType=problem-list-v2&envId=a72pyio7

class Solution {
public:
    int minimumPushes(string word) 
    {
        unordered_map<char,int> mp;

        for(char ch : word)
        {
            mp[ch]++;
        }   

        vector<pair<char,int>> v;

        for(auto [ch, n] : mp)
        {
            v.push_back({ch, n});
        }
        sort(v.begin(), v.end(),
        [](const pair<char,int>& l, const pair<char,int>& r) 
        { return l.second>r.second; });

        int cost=0;

        for(int i=0;i<v.size();i++)
        {
            int clicks=1;
            if(i+1>=8)
            {
                clicks+=i/8;
            }

            cost+=v[i].second*clicks;
        }

        return cost;
    }
};
