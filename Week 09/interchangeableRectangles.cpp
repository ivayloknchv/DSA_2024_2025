// https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles/description/

class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& r) 
    {
        unordered_map<double, long long> m;

        for(int i = 0; i < r.size(); i++)
        {
            double ratio = (r[i][0]*1.00)/r[i][1];

            m[ratio]++; 
        }    

        long long ans=0;
        
        for(auto& it : m)
        {
            ans+= it.second*(it.second-1)/2;
        }

        return ans;
    }
};
