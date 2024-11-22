#include <iostream>
#include<vector>
using namespace std;

// https://www.hackerrank.com/contests/sda-hw-6-2024/challenges/christmas-wishlists/problem

constexpr unsigned MOD = 1000000007;
constexpr unsigned MAX_TIME = 7 * 24 * 60;
constexpr unsigned MAX_SIZE = 1000;
unsigned dp[MAX_SIZE + 1][MAX_TIME + 1]{};
unsigned arr[MAX_SIZE]{};


int main()
{
    unsigned N = 0;
    cin >> N;

    for (unsigned i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    for (unsigned i = 0; i <= N; i++)
    {
        dp[i][0] = 1;
    }

    for (unsigned i = 1; i <= N; i++)
    {
        for (unsigned j = 1; j <= MAX_TIME; j++)
        {
            (dp[i][j] += dp[i - 1][j]) %= MOD;
            if (j >= arr[i - 1]) 
            {
                (dp[i][j] +=  dp[i - 1][j - arr[i - 1]]) %= MOD;
            }
        }
    }

    unsigned res = 0;

    for (unsigned i = 1; i <= MAX_TIME; i++)
    {
        res += dp[N][i];
        res %= MOD;
    }

    cout << res+1;
    return 0;
}
