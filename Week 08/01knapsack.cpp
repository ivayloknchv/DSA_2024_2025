// https://www.naukri.com/code360/problems/0-1-knapsack_920542?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

int knapsack(const vector<int>& weights, const vector<int>& values, int target)
{
    vector<vector<int>> dp(values.size() + 1, vector<int>(target + 1, 0));

    for (int i = 1; i <= weights.size(); i++)
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

    return dp[weights.size()][target];
}
