// https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/description/?envType=problem-list-v2&envId=binary-search

class Solution {
public:

    bool check(const vector<int>& quantities, int n, int test)
    {
        int counter=0;

        for(int q : quantities)
        {
            counter += (q / test);
            if(q % test)
            {
                counter++;
            }
        }

        return counter <= n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) 
    {
        int l = 1;
        int r = 100000;
        int ans=r;

        while(l <= r)
        {
            int m = l + (r - l) / 2;

            if(check(quantities, n, m))
            {
                r = m - 1;
                ans=min(ans,m);
            }
            else
            {
                l = m + 1;
            }
        }    

        return ans;
    }
};
