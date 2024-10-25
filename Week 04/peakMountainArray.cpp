// https://leetcode.com/problems/peak-index-in-a-mountain-array/description/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) 
    {
        int l = 0;
        int r = arr.size() - 1;

        while(l<=r)
        {
            int m = l + (r - l) / 2;

            if(arr[m-1]<arr[m] && arr[m] > arr[m+1])
            {
                return m;
            }
            else if(arr[m-1] > arr[m] && arr[m]>arr[m+1])
            {
                r = m ;
            }
            else
            {
                l = m ;
            }
        }

        return 0;
    }
};
