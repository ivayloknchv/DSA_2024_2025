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

// https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description/?envType=problem-list-v2&envId=awvsir0j

class Solution {
public:
    ListNode* doubleIt(ListNode* head) 
    {
        if(!head->next)
        {
            head->val*=2;
        }    
        else
        {
            head->val*=2;
            ListNode* curr=head;
            ListNode* next=head->next;

            while(curr && next)
            {
                next->val*=2;
                int carryOne=next->val/10;
                next->val%=10;

                if(carryOne)
                {
                    curr->val+=1;
                 }

                curr=next;
                next=next->next;
            }
        }
        if(head->val>=10)
        {
                ListNode* newHead= new ListNode(head->val/10);
                newHead->next=head;
                head->val%=10;
                return newHead;
        }
        return head;
    }
};
