// https://leetcode.ca/2021-04-14-1762-Buildings-With-an-Ocean-View/

vector<int> findBuildings(const vector<int>& heights)
{
    stack<pair<int,int>> st;

    vector<pair<int, int>> v;

    int n = heights.size();

    for (int i = 0; i < n; i++)
    {
        v.push_back({ heights[i], i });
    }

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top().first <= v[i].first)
        {
            st.pop();
        }
        st.push(v[i]);
    }

    vector<int> ans;

    while (!st.empty())
    {
        ans.push_back(st.top().second);
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
