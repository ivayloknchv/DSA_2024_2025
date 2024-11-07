/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// https://leetcode.com/problems/next-greater-node-in-linked-list/description/

class Solution {
public:

    vector<int> nextLargerNodes(ListNode* head) 
    {
        stack<pair<int,int>> st;
        vector<pair<int,int>> vec;

       ListNode* iter=head;
       int counter=0;

       while(iter)
       {
        vec.push_back({iter->val, counter++});
        iter=iter->next;
       }

       vector<int> ans(vec.size(), 0);

       for(int i = 0; i<vec.size(); i++)
       {
        while(!st.empty() && st.top().first<vec[i].first)
        {
            ans[st.top().second]=vec[i].first;
            st.pop();
        }
        st.push(vec[i]);
       }

       return ans;
    }
};
