// https://leetcode.com/problems/time-needed-to-buy-tickets/description/?envType=problem-list-v2&envId=queue

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) 
    {
        queue<pair<int,int>> q;

        for(int i = 0; i < tickets.size(); i++)
        {
            q.push({tickets[i], i});
        }
        int counter=1;

        while(!q.empty())
        {
            pair<int,int> curr=q.front();
            q.pop();
            --curr.first;
           
            if(curr.first==0 && curr.second==k)
            {
                return counter;
            }
            else if(curr.first!=0)
            {
                 q.push(curr);
            }
            counter++;
        }
        return -1;
    }
};
