#include <bits/stdc++.h> 
int knapsack(vector<int> weights, vector<int> values, int n, int target) 
{
	vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            int notToAdd = dp[i-1][j];
            int toAdd = 0;

            if (j - weights[i - 1] >= 0)
            {
                toAdd = dp[i - 1][j - weights[i - 1]] + values[i - 1];
            }
            dp[i][j] = max(toAdd, notToAdd);
        }
    }

	
    return dp[n][target];
}
