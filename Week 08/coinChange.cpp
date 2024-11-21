// https://leetcode.com/problems/coin-change/description/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        sort(coins.begin(), coins.end());

        vector<long long> memo(amount + 1, 0);

        for(int i = 1; i<=amount; i++)
        {
            long long minAns = INT_MAX;

            for(int j = 0; j<coins.size(); j++)
            {
                int diff= i - coins[j];

                if(diff<0)
                {
                    break;
                }
                minAns=min(minAns, 1 + memo[diff]);
            }

            memo[i] = minAns;
        }

         if(memo[memo.size()-1]!=INT_MAX)
         {
            return memo.back();
         }

         return -1;
    }
};
