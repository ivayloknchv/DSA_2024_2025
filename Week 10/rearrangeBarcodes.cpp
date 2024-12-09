// https://leetcode.com/problems/distant-barcodes/description/?envType=problem-list-v2&envId=heap-priority-queue

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) 
    {
        if(barcodes.size() == 0 || barcodes.size() == 1)
        {
            return barcodes;
        }
        
        vector<int> ans;

        unordered_map<int, int> m;

        for(int i = 0; i < barcodes.size(); i++)
        {
            m[barcodes[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, less<>>pq;

        for(auto& it : m)
        {
            pq.push({it.second, it.first});
        }

        while(!pq.empty())
        {
            auto f = pq.top();
            pq.pop();

            ans.push_back(f.second);
            f.first--;

            if(pq.size())
            {
                auto s = pq.top();
                pq.pop();

                ans.push_back(s.second);
                s.first--;
                if(s.first)
                {
                    pq.push(s);
                }
            }

            if(f.first)
            {
                pq.push(f);
            }
        }

        return ans;
    }
};
