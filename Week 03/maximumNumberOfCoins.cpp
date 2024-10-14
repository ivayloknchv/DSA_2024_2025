// https://leetcode.com/problems/maximum-number-of-coins-you-can-get/?envType=problem-list-v2&envId=an1ryio3

class Solution {
public:
    int maxCoins(vector<int>& piles) 
    {
        sort(piles.begin(), piles.end());

        int l=0;
        int r=piles.size()-1;
        int sum=0;

        while(l<=r)
        {
            sum+=piles[r-1];
            l++;
            r-=2;
        }

        return sum;
    }
};
