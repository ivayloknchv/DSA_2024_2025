// https://leetcode.com/problems/minimum-number-game/?envType=problem-list-v2&envId=heap-priority-queue

class Solution 
{
public:
    vector<int> numberGame(vector<int>& nums) 
    {
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());

        while(!pq.empty())
        {
            int alice = pq.top();
            pq.pop();

            int bob = pq.top();
            pq.pop();

            ans.push_back(bob);
            ans.push_back(alice);
        }   

        return ans;
    }
};
