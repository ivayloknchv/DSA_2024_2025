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
    ListNode* sortList(ListNode* head) 
    {
        vector<int> nums;

        ListNode* iter = head;

        while(iter)
        {
            nums.push_back(iter->val);
            iter=iter->next;
        }

        sort(nums.begin(), nums.end());

        iter=head;
        for(int i = 0; i < nums.size(); i++)
        {
            iter->val=nums[i];
            iter=iter->next;
        }

        return head;
    }
};
