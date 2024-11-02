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

// https://leetcode.com/problems/merge-in-between-linked-lists/description/?envType=problem-list-v2&envId=linked-list

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) 
    {
        ListNode* beg = nullptr;
        ListNode* end = nullptr;
        int counter = 0;

        ListNode* iter=list1;

        while(iter)
        {
            if(counter==a-1)
            {
                beg = iter;
            }
            if(counter==b+1)
            {
                end=iter;
                break;
            }
            iter=iter->next;
            counter++;
        }

        ListNode* secondTail=list2;

        while(secondTail && secondTail->next)
        {
            secondTail=secondTail->next;
        }
        beg->next=list2;
        secondTail->next=end;

        return list1;
    }
};
