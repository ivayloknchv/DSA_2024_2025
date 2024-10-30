// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/description/?envType=problem-list-v2&envId=linked-list

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
    int getPowOfTwo(ListNode* head)
    {
        int ans = 1;

        while(head)
        {
            ans*=2;
            head=head->next;
        }

        return ans;
    }

    int getDecimalValue(ListNode* head) 
    {
        int num = 0;
        int mult = getPowOfTwo(head)/2;

        while(head)
        {
            num+=mult*head->val;
            mult/=2;
            head=head->next;
        }   

        return num;
    }
};
