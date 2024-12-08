// https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/description/?envType=problem-list-v2&envId=heap-priority-queue

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) 
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        for(int i = 0; i<nums.size(); i++)
        {
            pq.push({nums[i], i});
        }

        for(int i = 0; i < k; i++)
        {
            auto x=pq.top();
            pq.pop();
            pq.push({multiplier*x.first, x.second});
            nums[x.second] = multiplier*x.first;
        }

        return nums;
    }
};
