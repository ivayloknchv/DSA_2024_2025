class Solution {
public:

    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> data;

        for(int i=0;i<names.size();i++)
        {
            data.push_back({heights[i], names[i]});
        }

        sort(data.begin(), data.end());

        vector<string> ans;

        for(int i=0;i<data.size();i++)
        {
            ans.push_back(data[data.size()-1-i].second);
        }

        return ans;
    }
};
