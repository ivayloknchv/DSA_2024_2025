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

// https://leetcode.com/problems/odd-even-linked-list/description/?envType=problem-list-v2&envId=linked-list

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) 
    {
        if(!head || !head->next)
        {
            return head;
        }

        ListNode *oddHead = nullptr, *oddTail = nullptr;
        ListNode *evenHead = nullptr, *evenTail = nullptr;
        ListNode* curr=head;

        bool isEven=false;
        int counter = 0;
        while(curr)
        {
            ListNode* temp = curr;
            curr=curr->next;
            temp->next=nullptr;

            if(!(counter & 1))
            {
                if(!evenHead)
                {
                    evenHead=temp;
                    evenTail=temp;
                }
                else
                {
                    evenTail->next=temp;
                    evenTail=temp;
                }
            }
            else
            {
                 if(!oddHead)
                {
                    oddHead=temp;
                    oddTail=temp;
                }
                else
                {
                    oddTail->next=temp;
                    oddTail=temp;
                }
            }
            counter++;
        }

        evenTail->next=oddHead;
        return evenHead;
    }
};
