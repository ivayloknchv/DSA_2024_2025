// https://leetcode.com/problems/valid-perfect-square/?envType=problem-list-v2&envId=binary-search

class Solution {
public:
    bool isPerfectSquare(int num) 
    {
        long long l = 0;
        long long r = num;

        while(l <= r)
        {
            long long mid = l + (r - l) / 2;

            if(mid*mid==num)
            {
                return true;
            }

            else if(mid*mid<num)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }    

        return false;
    }
};
