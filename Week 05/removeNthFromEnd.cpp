// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

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
    int getSize(ListNode* head)
    {
        int size=0;

        while(head)
        {
            size++;
            head=head->next;
        }
        return size;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if(!head)
        {
            return nullptr;
        }

        int pos = getSize(head)-n;

        if(pos==0)
        {
            return head->next;
        }

        ListNode* curr=head;
        ListNode* prev=nullptr;

        for(int i = 0; i < pos;i++)
        {
            if(curr)
            {
                prev=curr;
                curr=curr->next;
            }
            else
            {
                return head;
            }
        }    
        prev->next=curr->next;

        return head;
    }
};
