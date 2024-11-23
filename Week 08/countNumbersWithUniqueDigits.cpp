class Solution {
public:
    int countNumbersWithUniqueDigits(int n) 
    {
        if(n==0)
        {
            return 1;
        }
        vector<int> memo(n+1);
        memo[0]=1;
        memo[1]=9;
        int counter = 9;

        for(int i = 2; i <= n; i++)
        {
            memo[i] = memo[i-1]*(counter--);
        }

        int ans = 0;

        for(int m : memo)
        {
            ans+=m;
        }

        return ans;
    }
};
