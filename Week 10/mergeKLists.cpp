// https://leetcode.com/problems/merge-k-sorted-lists/description/

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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue<pair<int,int>,  vector<pair<int,int>>, greater<>>pq;

        ListNode* head=nullptr;
        ListNode* curr=nullptr;

        for(int i = 0; i < lists.size(); i++)
        {
            if(lists[i])
            {
                pq.push({lists[i]->val, i});
                lists[i]=lists[i]->next;
            }
        }

        while(!pq.empty())
        {
            int currVal=pq.top().first;
            int currIdx=pq.top().second;
            pq.pop();

            if(lists[currIdx])
            {
                pq.push({lists[currIdx]->val, currIdx});
                lists[currIdx]=lists[currIdx]->next;
            }

            ListNode* newNode= new ListNode(currVal);

            if(!head)
            {
                head=curr=newNode;
            }
            else
            {
                curr->next=newNode;
                curr=curr->next;
            }
        }
        return head;    
    }
};
