// https://leetcode.com/problems/sort-an-array/description/?envType=problem-list-v2&envId=heap-priority-queue

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) 
    {
         priority_queue <int, vector<int>, greater<int> > pq(nums.begin(), nums.end());

         vector<int> ans;

         while(!pq.empty())
         {
            ans.push_back(pq.top());
            pq.pop();
         }

         return ans;
    }
};
