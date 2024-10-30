// https://leetcode.com/problems/palindrome-linked-list/description/

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

    bool isPalindrome(ListNode* head) 
    {
        if(!head || !head->next)
        {
            return true;
        }

        ListNode* slow=head;
        ListNode* fast=head;

        while(slow && fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* secondHead=slow;

        if(fast)
        {
            secondHead=secondHead->next;
        }

        ListNode* curr = secondHead;
        ListNode* prev = nullptr;

        while(curr)
        {
            ListNode* next=curr->next;

            curr->next=prev;

            prev=curr;
            curr=next;
        }

        secondHead = prev;

        while(head && secondHead)
        {
            if(head->val != secondHead->val)
            {
                return false;
            }
            head=head->next;
            secondHead=secondHead->next;
        }

        return true;
    }
};
