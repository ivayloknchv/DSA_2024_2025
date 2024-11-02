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

// https://leetcode.com/problems/rotate-list/description/?envType=problem-list-v2&envId=linked-list

class Solution {
public:

    ListNode* findTail(ListNode* head)
    {
        ListNode* iter=head;

        while(iter && iter->next)
        {
            iter=iter->next;
        }
        return iter;
    }

    int getLen(ListNode* head)
    {
        int counter=0;

        while(head)
        {
            head=head->next;
            counter++;
        }
        return counter;
    }

    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(!head)
        {
            return nullptr;
        }

        ListNode* tail=findTail(head);
        
        int len = getLen(head);

        tail->next=head;

        int toFind = len - (k%len);

        ListNode* iter=head;

        for(int i = 1; i<toFind; i++)
        {
            iter=iter->next;
        }

        ListNode* newHead=iter->next;
        iter->next=nullptr;

        return newHead;
    }
};
