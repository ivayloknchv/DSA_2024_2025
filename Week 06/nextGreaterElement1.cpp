// https://leetcode.com/problems/next-greater-element-i/description/?envType=problem-list-v2&envId=monotonic-stack

class Solution 
{
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int, int> numsMap;

        for(int num : nums1)
        {
            numsMap[num]=-1;
        }

        stack<int> st;

        for(int i = 0; i < nums2.size(); i++)
        {
            while(!st.empty() && st.top()<nums2[i])
            {
                numsMap[st.top()]=nums2[i];
                st.pop();
            }

            st.push(nums2[i]);
        }

        vector<int> ans;

        for(int i = 0; i<nums1.size(); i++)
        {
            ans.push_back(numsMap[nums1[i]]);
        }

        return ans;
    }
};
