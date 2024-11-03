/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// https://leetcode.com/problems/linked-list-cycle-ii/description/

class Solution {
public:

    ListNode *detectCycle(ListNode *head) 
    {
        if(!head)
        {
            return nullptr;
        }

        ListNode* slow=head;
        ListNode* fast=head;

        while(slow && fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast)
            {
                slow=head;

                while(slow!=fast)
                {
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }        
        return nullptr;
    }
};
