// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/?envType=problem-list-v2&envId=binary-search

class Solution {
public:

    bool check(const vector<int>& weights, int test, int days)
    {
        int daysCounter = 1;
        int testSum=0;

        for(int w : weights)
        {
            if(w>test)
            {
                return false;
            }

            testSum+=w;

            if(testSum>test)
            {
                daysCounter++;
                testSum=w;
            }
        }

        return daysCounter<=days;
    }

    int shipWithinDays(vector<int>& weights, int days) 
    {
        int sum = 0;

        for(int w : weights)
        {
            sum+=w;
        }

        int l = 0;
        int r = sum;
        int ans=INT_MAX;

        while (l<=r)
        {
            int m = l + (r - l) / 2;

            if(check(weights, m, days))
            {
                ans=min(ans, m);
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }

        return ans;
    }
};
