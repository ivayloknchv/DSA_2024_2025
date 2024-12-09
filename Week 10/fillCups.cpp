// https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/description/

class Solution {
public:
    int fillCups(vector<int>& amount) 
    {
        priority_queue<int, vector<int>, less<>>pq;

        for(int i = 0; i < 3; i++)
        {
            if(amount[i])
            {
                pq.push(amount[i]);
            }
        }

        int counter = 0;

        while(!pq.empty())
        {
            if(pq.size()>1)
            {
                int first = pq.top();
                pq.pop();
                first--;
                int second = pq.top();
                pq.pop();
                second--;

                if(first)
                {
                    pq.push(first);
                }
                if(second)
                {
                    pq.push(second);
                }
            }

            else if(pq.size()==1)
            {
                int t = pq.top();
                t--;
                pq.pop();

                if(t)
                {
                    pq.push(t);
                }
            }      
            counter++;
        }
        return counter;
    }
};
