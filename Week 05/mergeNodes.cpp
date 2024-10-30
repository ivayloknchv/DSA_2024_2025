// https://leetcode.com/problems/merge-nodes-in-between-zeros/?envType=problem-list-v2&envId=linked-list

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
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) 
    {
        if(!head || !head->next)
        {
            return nullptr;
        }

        ListNode* ans = nullptr;

        ListNode* iter = head;

        ListNode* curr=nullptr;
        ListNode* prev=nullptr;

        while(iter)
        {
            if(iter->val==0)
            {
                iter=iter->next;
                continue;
            }

            int sum = 0;

            while(iter && iter->val!=0)
            {
                sum+=iter->val;
                iter=iter->next;
            }

            curr=new ListNode(sum);

            if(!ans)
            {
                ans=curr;
                prev=curr;
            }
            else
            {
                prev->next=curr;
                prev=curr;
            }
        }
        return ans;
    }
};
