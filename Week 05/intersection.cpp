// https://leetcode.com/problems/intersection-of-two-linked-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    int size(ListNode* head)
    {
        int n = 0;

        while(head)
        {
            n++;
            head=head->next;
        }

        return n;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        if(!headA || !headB)
        {
            return nullptr;
        }

        int sizeA=size(headA);
        int sizeB=size(headB);

        while(sizeA>sizeB)
        {
            headA=headA->next;
            sizeA--;
        } 

        while(sizeB > sizeA)
        {
            headB=headB->next;
            sizeB--;  
        } 

        while(headA && headB)
        {
            if(headA==headB)
            {
                return headA;
            }

            headA=headA->next;
            headB=headB->next;
        }

        return nullptr;
    }
};
