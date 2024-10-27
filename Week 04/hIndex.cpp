// https://leetcode.com/problems/h-index-ii/description/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l = 0;
        int r=citations.size()-1;
        int ans=0;


        while(l<=r)
        {
            int m = l +(r-l)/2;
            int h=citations.size()-m;

            if(h<=citations[m])
            {
                r=m-1;
                ans=max(ans,h);
            }
            else
            {
                l=m+1;
            }


        }
        return ans;

    }
};
