/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

// https://leetcode.com/problems/guess-number-higher-or-lower/description/?envType=problem-list-v2&envId=binary-search

class Solution {
public:
    int guessNumber(int n) 
    {
        int l = 1;
        int r = n;

        while (l<=r)
        {
            int mid = l + (r - l) / 2;

            if(!guess(mid))
            {
                return mid;
            }

            else if(guess(mid)<0)
            {
                r = mid - 1;
            }

            else
            {
                l = mid + 1;
            }
        }  

        return 0;
    }
};
