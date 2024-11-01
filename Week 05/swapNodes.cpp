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

// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/description/?envType=problem-list-v2&envId=awvsir0j

class Solution {
public:

    int listLen(ListNode* head)
    {
        if(!head)
        {
            return 0;
        }

        int len=0;

        while(head)
        {
            len++;
            head=head->next;
        }

        return len;
    }

    ListNode* swapNodes(ListNode* head, int k) 
    {
        if(!head || !head->next)
        {
            return head;
        }
        int len = listLen(head);

        ListNode *first=nullptr, *second = nullptr;

        int end=len+1-k;
        int counter=1;
        ListNode* iter=head;

        while(iter)
        {
            if(counter==k)
            {
                first=iter;
            }
            if(counter==end)
            {
                second=iter;
            }
            iter=iter->next;
            counter++;
        }

        if(first!=second)
        {
        swap(first->val, second->val);
        }

        return head;
    }
};
