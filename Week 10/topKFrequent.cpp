// https://leetcode.com/problems/top-k-frequent-words/description/?envType=problem-list-v2&envId=heap-priority-queue

struct MyCmp
{
    bool operator()(const pair<int,string>& lhs, const pair<int,string>&rhs)
    {
        if(lhs.first == rhs.first)
        {
            return lhs.second<rhs.second;
        }
        return lhs.first>rhs.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        unordered_map<string, int> m;

        for(string w : words)
        {
            m[w]++;
        }

        vector<pair<int, string>>v;

        for(auto& i : m)
        {
            v.push_back({i.second, i.first});
        }

        MyCmp cmp;
        priority_queue<pair<int, string>, vector<pair<int, string>>, MyCmp> pq(cmp);

        for(int i = 0; i<k; i++)
        {
            pq.push(v[i]);
        }

        for(int i = k; i<v.size(); i++)
        {
            if(cmp(v[i], pq.top()))
            {
                pq.pop();
                pq.push(v[i]);
            }
        }

        vector<string> ans;

        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
