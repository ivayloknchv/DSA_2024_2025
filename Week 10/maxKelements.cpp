// https://leetcode.com/problems/maximal-score-after-applying-k-operations/description/

class Solution 
{
public:
    long long maxKelements(vector<int>& nums, int k) 
    {
        priority_queue<int> pq(nums.begin(), nums.end());

        long long score=0;

        for(int i = 0; i < k; i++)
        {
           int curr = pq.top();
           score+=curr;
           pq.pop();
           pq.push(ceil(curr/3.00));
        }

        return score;
    }
};
