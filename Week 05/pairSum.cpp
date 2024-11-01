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

// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/?envType=problem-list-v2&envId=amgo332d

class Solution {
public:
    int pairSum(ListNode* head) 
    {
        if(!head)
        {
            return 0;
        }

        ListNode* slow=head;
        ListNode* fast=head;

        while(slow && fast)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* curr=slow;
        ListNode* prev=nullptr;

        while(curr)
        {
            ListNode* next=curr->next;

            curr->next=prev;
            prev=curr;
            curr=next;
        }

        ListNode* firstHead=head;
        ListNode* secondHead=prev;

        int maxSum=INT_MIN;

        while(firstHead && secondHead)
        {
            int currentSum=firstHead->val+secondHead->val;
            maxSum=max(maxSum, currentSum);
            firstHead=firstHead->next;
            secondHead=secondHead->next;
        }

        return maxSum;
    }
};
