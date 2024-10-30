// https://leetcode.com/problems/delete-node-in-a-linked-list/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) 
    {
        if(!node)
        {
            return;
        }
        
        ListNode* nextNode=node->next;
        node->val=nextNode->val;
        node->next=nextNode->next;
    }
};
