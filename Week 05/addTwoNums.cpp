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

// https://leetcode.com/problems/add-two-numbers/description/?envType=problem-list-v2&envId=linked-list

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        if(!l1 && !l2)
        {
            return nullptr;
        }
        if(!l1)
        {
            return l2;
        }
        if(!l2)
        {
            return l1;
        }

        ListNode* newHead=nullptr;
        ListNode* curr=nullptr;
        ListNode* prev=nullptr;
        bool carryOne=0;

        while(l1 && l2)
        {
            int num=l1->val + l2->val + carryOne;
            carryOne=num/10;
            num%=10;

            curr=new ListNode(num);
            l1=l1->next;
            l2=l2->next;

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

        while(l1)
        {
            int num=l1->val+carryOne;
            carryOne=num/10;
            num%=10;

            curr=new ListNode(num);
            l1=l1->next;

            prev->next=curr;
            prev=curr;            
        }
        while(l2)
        {
            int num=l2->val+carryOne;
            carryOne=num/10;
            num%=10;

            curr=new ListNode(num);
            l2=l2->next;

            prev->next=curr;
            prev=curr;
        }
       
        if(carryOne)
        {
            ListNode* finalNode=new ListNode(carryOne);
            curr->next=finalNode;
        }
        return newHead;
    }
};
