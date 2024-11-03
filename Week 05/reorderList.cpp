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

// https://leetcode.com/problems/reorder-list/description/?envType=problem-list-v2&envId=linked-list

class Solution {
public:
    void reorderList(ListNode* head) 
    {
        if(!head || !head->next)
        {
            return;
        }

        ListNode* slow=head;
        ListNode* fast=head;

        while(slow && fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* secondIter=slow;

        ListNode* curr=slow;
        ListNode* prev=nullptr;

        while(curr)
        {
            ListNode*next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }

        secondIter=prev;
        ListNode* iter=head;

        while(secondIter && secondIter->next)
        {
            ListNode* next=iter->next;
            ListNode* secondNext=secondIter->next;
            iter->next=secondIter;
            secondIter->next=next;

            secondIter=secondNext;
            iter=next;
        }

    }
};
