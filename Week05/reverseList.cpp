// https://leetcode.com/problems/reverse-linked-list/?envType=problem-list-v2&envId=linked-list 

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
    ListNode* reverseList(ListNode* head) 
    {
        if(!head)
        {
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = curr->next;

        while(curr)
        {
            curr->next=prev;

            prev=curr;
            curr=next;
        }

        return prev;
    }
};
