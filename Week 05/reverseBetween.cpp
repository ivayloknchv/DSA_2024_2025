// https://leetcode.com/problems/reverse-linked-list-ii/description/

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
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if(!head)
        {
            return nullptr;
        }

        int counter=1;
        ListNode* prev= nullptr, *curr=head, *beg=nullptr, 
        *end=nullptr, *beforeBeg=nullptr, *afterEnd=nullptr;

        while(curr)
        {
            if(counter==left)
            {
                beg=curr;
                beforeBeg=prev;
            }
            if(counter==right)
            {
                end=curr;
                afterEnd=curr->next;
                break;
            }
            counter++;
            prev=curr;
            curr=curr->next;
        }

        prev = nullptr;
        ListNode* begCopy=beg;
        curr = beg;
        counter=0;
        while(curr && counter++ <= right-left)
        {
            ListNode* next = curr->next;

            curr->next=prev;
            prev=curr;
            curr=next;            
        }

        if(beforeBeg)
        {
            beforeBeg->next=prev;
        }
        else
        {
            head=prev;
        }

        begCopy->next=afterEnd;

        return head;
    }
};
