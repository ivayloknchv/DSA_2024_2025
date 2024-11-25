// https://leetcode.com/problems/take-gifts-from-the-richest-pile/description/?envType=problem-list-v2&envId=heap-priority-queue

class Solution 
{
public:
    long long pickGifts(vector<int>& gifts, int k) 
    {
        priority_queue<int> pq(gifts.begin(), gifts.end());

        for(int i = 0; i<k; i++)
        {
            int val = pq.top();
            pq.pop();
            pq.push(floor(sqrt(val)));
        }

        long long ans=0;

        while(!pq.empty())
        {
            ans+=pq.top();
            pq.pop();
        }

        return ans;
    }
};
