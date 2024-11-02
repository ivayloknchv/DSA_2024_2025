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

// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/?envType=problem-list-v2&envId=linked-list

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) 
    {
        if(!head || !head->next)
        {
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(slow && fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* iter=head;

        while(iter && iter->next != slow)
        {
            iter=iter->next;
        }

        iter->next=slow->next;

        return head;
    }
};
