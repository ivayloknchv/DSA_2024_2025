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

     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        if(!list1 && !list2)
        {
            return nullptr;
        }
        else if(!list1)
        {
            return list2;
        }
        else if(!list2)
        {
            return list1;
        }

        ListNode* curr=nullptr;
        ListNode* prev=nullptr;
        ListNode* ans=nullptr;

        while(list1 && list2)
        {
            if(list1->val <= list2->val)
            {
                curr=list1;
                list1=list1->next;
                curr->next=nullptr;
            }
            else
            {
                curr=list2;
                list2=list2->next;
                curr->next=nullptr;
            }

            if(!ans)
            {
                ans=curr;
                prev=curr;
            }
            else
            {
                prev->next=curr;
                prev=curr;
            }
        }

       while(list1)
        {
            curr=list1;
            list1=list1->next;
            curr->next=nullptr;
            prev->next=curr;
            prev=curr;
        }

        while(list2)
        {
            curr=list2;
            list2=list2->next;
            curr->next=nullptr;
             prev->next=curr;
            prev=curr;
        }
        return ans;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if(lists.size()==0)
        {
            return nullptr;
        }
        if(lists.size()==1)
        {
            return lists[0];
        }

        ListNode* merged=mergeTwoLists(lists[0],lists[1]);

        for(int i = 2; i < lists.size(); i++)
        {
            merged=mergeTwoLists(merged, lists[i]);
        }

        return merged;
    }
};
