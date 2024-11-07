// https://leetcode.com/problems/daily-temperatures/description/

class Solution 
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        vector<pair<int,int>> temps;
        stack<pair<int,int>> st;
        vector<int> ans(temperatures.size(), 0);

        for(int i = 0; i < temperatures.size(); i++)
        {
            temps.push_back({temperatures[i], i});
        }

        for(int i = 0; i < temps.size(); i++)
        {
            while(!st.empty() && st.top().first < temps[i].first)
            {
                ans[st.top().second]=abs(st.top().second-temps[i].second);
                st.pop();
            }
            st.push(temps[i]);
        }   

        return ans;
    }
};
