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

// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/?envType=problem-list-v2&envId=linked-list

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(!head)
        {
            return nullptr;
        }

        while(head)
        {
            int currentNum=head->val;
            int counter = 0;

            ListNode* checker=head;

            while(checker && checker->val==currentNum)
            {
                counter++;
                checker=checker->next;
            }

            if(counter == 1)
            {
                break;
            }
            else
            {
                head=checker;
            }
        }

        ListNode* iter = head;
        ListNode* prev = nullptr;
        while(iter)
        {
            int currentNum = iter -> val;
            ListNode* checker = iter;
            int counter = 0;

            while(checker && checker->val == currentNum)
            {
                counter++;
                checker = checker->next;
            }
            
            if(counter==1)
            {
                prev=iter;
                iter=iter->next;
            }
            else
            {
                prev->next=checker;
                iter=checker;
            }
        }
        return head;
    }
};
