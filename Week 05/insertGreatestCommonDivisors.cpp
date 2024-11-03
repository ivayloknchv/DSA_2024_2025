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

// https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/?envType=problem-list-v2&envId=linked-list

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) 
    {
        if(!head || !head->next)
        {
            return head;
        }

        ListNode* iter=head;

        while(iter && iter->next)
        {
            int gcdRes=gcd(iter->val, iter->next->val);

            ListNode* next=iter->next;
            ListNode* toAdd=new ListNode(gcdRes);
            iter->next=toAdd;
            toAdd->next=next;
            iter=next;
        }

        return head;
    }
};
