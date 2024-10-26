// https://leetcode.com/problems/koko-eating-bananas/description/?envType=problem-list-v2&envId=binary-search

class Solution 
{
public:

    bool check(const vector<int>& piles, int h, int k)
    {
        long long res=0;

    for (int pile : piles)
    {
        if (pile % k != 0)
        {
            res += (pile / k) + 1;
        }
        else
        {
            res += pile / k;
        }
    }

        return res<=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int l = 1;
        
        int r = piles[0];

        for(int i = 1; i<piles.size(); i++)
        {
            if(r < piles[i])
            {
                r = piles[i];
            }
        }

        int ans = INT_MAX;
        while(l <= r)
        {
            int mid = l + (r - l) / 2;

            if(check(piles, h, mid))
            {
                ans = min(ans, mid);
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return ans;
    }
};
