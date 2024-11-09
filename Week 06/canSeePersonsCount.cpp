// https://leetcode.com/problems/number-of-visible-people-in-a-queue/description/

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& h) 
    {
        vector<int> ans(h.size());
        vector<pair<int,int>> v;
        stack<pair<int,int>> st;

        for(int i = 0; i < h.size(); i++)
        {
            v.push_back({h[i], i});
        }

        for(int i = 0; i < v.size(); i++)
        {
            while(!st.empty() && st.top().first<v[i].first)
            {
                ans[st.top().second]++;
                st.pop();
            }

            if(!st.empty())
            {
                ans[st.top().second]++;
            }
            st.push(v[i]);
        }

        return ans;
    }
};
