// https://leetcode.com/problems/find-the-distance-value-between-two-arrays/description/?envType=problem-list-v2&envId=binary-search

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) 
    {
        sort(arr2.begin(), arr2.end());

        int count =0;

        for(int i = 0; i < arr1.size(); i++)
        {
            int currentNum = arr1[i];

            int l = 0;
            int r = arr2.size() - 1;

            bool check = true;

            while(l<=r)
            {
                int m = l + (r - l) / 2;

                int dist = abs(currentNum-arr2[m]);

                if(dist<=d)
                {
                    check = false;
                    break;
                }
                else if(arr2[m]>currentNum)
                {
                    r = m - 1;
                }
                else
                {
                    l = m + 1;
                }
            }

            if(check)
            {
                count++;
            }
        }

        return count;
    }
};
