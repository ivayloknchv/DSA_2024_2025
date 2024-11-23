#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// https://www.hackerrank.com/contests/sda-2022-2023-test7-123-43/challenges/1-454/problem

int main()
{
    int n = 0;
    cin >> n;
    vector<vector<long long>> m(n, vector<long long>(n, 0));
    vector<vector<bool>> diag(n, vector<bool>(n, 0));
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }
    }
    
    long long q=0;
    cin>>q;
    
    while(q--)
    {
        int a = 0, b =0;
        cin>>a>>b;
        diag[a][b]=true;
    }
    
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    dp[0][0] = m[0][0];
    for (int i = 1; i < n; i++)
    {
        dp[0][i] = m[0][i]+dp[0][i - 1];
    }
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = m[i][0]+dp[i - 1][0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if(diag[i][j])
            {
                dp[i][j] = m[i][j] + max(dp[i-1][j-1],max(dp[i - 1][j], dp[i][j - 1]));
            }
            else
            {
                dp[i][j] = m[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    cout<<dp[n-1][n-1];
    return 0;
}
