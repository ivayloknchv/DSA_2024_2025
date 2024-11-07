// https://leetcode.com/problems/next-greater-element-ii/description/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
             stack<pair<int,int>> st;
             vector<int> ans(nums.size(), -1);

             for(int i  = 0; i<nums.size(); i++)
             {
                while(!st.empty() && st.top().first < nums[i])
                {
                    ans[st.top().second]=nums[i];
                    st.pop();
                }
                st.push({nums[i], i});
             }
             for(int i  = 0; i<nums.size(); i++)
             {
                while(!st.empty() && st.top().first < nums[i])
                {
                    ans[st.top().second]=nums[i];
                    st.pop();
                }
                st.push({nums[i], i});
             }
             return ans;

    }
};
