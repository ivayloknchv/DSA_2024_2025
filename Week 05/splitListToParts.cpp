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

// https://leetcode.com/problems/split-linked-list-in-parts/description/?envType=problem-list-v2&envId=amgo332d

class Solution {
public:

    int getSize(ListNode* head)
    {
        int size = 0;

        while(head)
        {
            size++;
            head=head->next;
        }

        return size;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        if(!head)
        {
            vector<ListNode*> toReturn(k);
            return toReturn;
        }

        vector<ListNode*> toReturn;

        int size=getSize(head);
        int listLen=size/k;

        ListNode* iter = head;
        ListNode* newHead = nullptr;
        ListNode* prev = nullptr;
        int extraOneTotal = size % k;
        int extraOneCounter = 0;

       while(iter)
        {
            newHead = nullptr;
            prev = nullptr;
            int counter = 0;
            int carryOne = false;

            if(extraOneCounter < extraOneTotal)
            {
                extraOneCounter++;
                carryOne = true;
            }
            
            while(iter && counter < listLen + carryOne)
            {
                ListNode* toAdd = new ListNode(iter->val);

                iter=iter->next;

                if(!newHead)
                {
                    newHead=toAdd;
                    prev=toAdd;
                }
                else
                {
                    prev->next=toAdd;
                    prev=toAdd;
                }
                counter++;
            }

            toReturn.push_back(newHead);
        }

        int emptyLists=k-toReturn.size();

        for(int i = 0; i< emptyLists; i++)
        {
            ListNode* empty;
            toReturn.push_back(empty);
        }

        return toReturn;
    }
};
