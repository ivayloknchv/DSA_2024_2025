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

// https://leetcode.com/problems/add-two-numbers-ii/description/?envType=problem-list-v2&envId=linked-list

class Solution {
public:

    ListNode* reverse(ListNode* l)
    {
        ListNode* curr=l;
        ListNode* prev=nullptr;

        while(curr)
        {
            ListNode* next = curr ->next;

            curr->next=prev;
            prev=curr;
            curr=next;
        }

        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        l1=reverse(l1);
        l2=reverse(l2);

        bool carryOne=false;

        ListNode *l1Iter=l1, *l2Iter=l2;
        ListNode* curr=nullptr;
        ListNode* prev=nullptr;
        ListNode* newHead=nullptr;
        
        while(l1Iter && l2Iter)
        {
            int newVal=l1Iter->val + l2Iter->val + carryOne;
            carryOne=newVal/10;
            newVal%=10;

            curr = new ListNode(newVal);

            l1Iter=l1Iter->next;
            l2Iter=l2Iter->next;

            if(!newHead)
            {
                newHead=curr;
                prev=curr;
            }
            else
            {
                prev->next=curr;
                prev=curr;
            }
        }

        while(l1Iter)
        {
            int newVal=l1Iter->val + carryOne;
            carryOne=newVal/10;
            newVal%=10;

            curr = new ListNode(newVal);

            l1Iter=l1Iter->next;
            prev->next=curr;
            prev=curr;
        }

        while(l2Iter)
        {
            int newVal=l2Iter->val + carryOne;
            carryOne=newVal/10;
            newVal%=10;

            curr = new ListNode(newVal);

            l2Iter=l2Iter->next;
            prev->next=curr;
            prev=curr;
        }

        if(carryOne)
        {
            ListNode* last=new ListNode(carryOne);
            prev->next=last;
            prev=last;
        }

        return reverse(newHead);
    }
};
