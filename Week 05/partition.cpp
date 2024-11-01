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

// https://leetcode.com/problems/partition-list/description/?envType=problem-list-v2&envId=awvsir0j

class Solution {
public:
    ListNode* partition(ListNode* head, int x) 
    {
        if(!head)
        {
            return nullptr;
        }

        ListNode *curr=head, *leftHead=nullptr, *leftPrev=nullptr,*leftIter=nullptr, 
        *rightHead=nullptr, *rightPrev=nullptr, *rightIter=nullptr;

        while(curr)
        {
            if(curr->val < x)
            {
                leftIter=curr;
                curr=curr->next;
                leftIter->next=nullptr;

                if(!leftHead)
                {
                    leftHead=leftIter;
                    leftPrev=leftIter;
                }
                else
                {
                    leftPrev->next=leftIter;
                    leftPrev=leftPrev->next;
                }
            }
            else
            {
                rightIter=curr;
                curr=curr->next;
                rightIter->next=nullptr;

                if(!rightHead)
                {
                    rightHead=rightIter;
                    rightPrev=rightIter;
                }
                else
                {
                    rightPrev->next=rightIter;
                    rightPrev=rightPrev->next;
                }
            }
        }

        if(!leftHead)
        {
            return rightHead;
        }
        if(!rightHead)
        {
            return leftHead;
        }

        leftPrev->next=rightHead;
        return leftHead;
    }
};
