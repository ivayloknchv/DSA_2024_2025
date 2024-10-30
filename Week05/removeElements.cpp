// removeElements

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
class Solution 
{
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        if(!head)
        {
            return nullptr;
        }

       while(head)
       {
            if(head->val==val)
            {
                head=head->next;
            }
            else
            {
                break;
            }
       }

       ListNode* curr = head;
       ListNode* prev = nullptr;

       while(curr)
       {
            if(curr->val == val)
            {
                curr=curr->next;
                prev->next=curr;
            }
            else
            {
                prev=curr;
                curr=curr->next;
            }
       }
       return head;
    }
};
