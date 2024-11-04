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

// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/?envType=problem-list-v2&envId=linked-list

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) 
    {
        if(!head)
        {
            return {-1,-1};
        }    
        vector<int> positions;

        int counter = 1;
        ListNode* iter=head;

        while(iter && iter->next &&iter->next->next)
        {
            int a = iter->val;
            int b = iter->next->val;
            int c = iter->next->next->val;

            if ((a<b && b>c) || (a>b && b<c))
            {
                positions.push_back(counter);
            }
            counter++;
            iter=iter->next;
        }

        if(positions.size()<2)
        {
            return {-1, -1};
        }

        int maxDiff=abs(positions[0]-positions[positions.size()-1]);
        int minDiff= INT_MAX;

        for(int i = 1; i<positions.size();i++)
        {
            minDiff=min(minDiff, positions[i]-positions[i-1]);
        }

        return {minDiff, maxDiff};
    }
};
