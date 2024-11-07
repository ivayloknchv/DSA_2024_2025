// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/description/?envType=problem-list-v2&envId=stack

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) 
    {
        vector<int> discounts = prices;
        stack<pair<int,int>> st;
        vector<pair<int,int>> vec;

        for(int i = 0; i < prices.size(); i++)
        {
            vec.push_back({prices[i], i});
        }

        for(int i = 0; i<prices.size(); i++)
        {
            while(!st.empty() && vec[i].first<=st.top().first)
            {
                discounts[st.top().second] = abs(vec[i].first-st.top().first);
                st.pop();
            }
            st.push(vec[i]);
        }
        return discounts;
    }
};
