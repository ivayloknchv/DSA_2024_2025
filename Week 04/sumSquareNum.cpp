https://leetcode.com/problems/sum-of-square-numbers/description/?envType=problem-list-v2&envId=binary-search

class Solution {
public:
    bool judgeSquareSum(int c) 
    {
        long long l = 0;
        long long r = sqrt(c);

        long long target=c;
        while(l<=r)
        {
            long long res=l*l+r*r;

            if(res==target)
            {
                return true;
            }
            else if(res<target)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return false; 
    }
};
