// https://leetcode.com/problems/last-stone-weight/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        priority_queue<int> pq(stones.begin(), stones.end());

        while(pq.size()!=1)
        {
            int m1=pq.top();
            pq.pop();
            int m2=pq.top();
            pq.pop();

            if(m1==m2)
            {
                if(pq.empty())
                {
                    return 0;
                }
            }
            else
            {
                pq.push(m1-m2);
            }
        }  

        return pq.top();
    }
};
