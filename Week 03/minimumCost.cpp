// https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/description/?envType=problem-list-v2&envId=an1ryio3

class Solution {
public:
    int minimumCost(vector<int>& cost) 
    {
        int counter=0;
        int sum=0;

        sort(cost.begin(), cost.end());

        for(int i=cost.size()-1;i>=0;i--)
        {
            sum+=cost[i];
            counter++;

            if(counter==3)
            {
                sum-=cost[i];
                counter=0;
            }
        }

        return sum;
    }
};
