// https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/description/?envType=problem-list-v2&envId=an1rjax7
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());

        for(int i=0;i<arr.size();i++)
        {
            if(target[i]!=arr[i])
            {
                return false;
            }
        }

        return true;
    }
};
