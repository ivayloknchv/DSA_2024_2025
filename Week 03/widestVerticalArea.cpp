// https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/description/?envType=problem-list-v2&envId=an1phfb2

class Solution {
public:

static bool compare(vector<int> p1, vector<int> p2)
{
    return (p1[0]<p2[0]) || (p1[0]==p2[0] && p1[1]<p2[1]);
}
    int maxWidthOfVerticalArea(vector<vector<int>>& points) 
    {
        sort(points.begin(), points.end(), compare);

        int max=points[1][0]-points[0][0];

        for(int i=1;i<points.size()-1; i++)
        {
            int curr=points[i+1][0]-points[i][0];

            if(curr>max)
            {
                max=curr;
            }
        }

        return max;
    }
};
