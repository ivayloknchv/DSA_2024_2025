// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/description/?envType=problem-list-v2&envId=an1phfb2
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) 
    {
        sort(arr.begin(), arr.end());

        int diff=arr[1]-arr[0];

        for(int i=1;i<arr.size()-1;i++)
        {
            if(diff!=arr[i+1]-arr[i])
            {
                return false;
            }
        }

        return true;
    }
};
