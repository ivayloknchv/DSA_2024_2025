// https://leetcode.com/problems/k-closest-points-to-origin/description/?envType=problem-list-v2&envId=awdef2cg

class Solution {
public:

    static bool compare(const vector<int>& lhs, const vector<int>& rhs)
    {
        int dist1=lhs[0]*lhs[0] + lhs[1]*lhs[1];
        int dist2=rhs[0]*rhs[0] + rhs[1]*rhs[1];

        return dist1<dist2;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        sort(points.begin(), points.end(), compare);

        vector<vector<int>> res(k);

        for(int i=0;i<k;i++)
        {
            res[i]=points[i];
        }

        return res;
    }
};
