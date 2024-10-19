// https://leetcode.com/problems/minimum-rectangles-to-cover-points/description/?envType=problem-list-v2&envId=awdeugtv

class Solution {
public:

static bool cmp(const vector<int>& lhs, const vector<int>& rhs)
{
    if (lhs[0] == rhs[0])
    {
        return lhs[1] < rhs[1];
    }

    return lhs[0] < rhs[0];
}

int minRectanglesToCoverPoints(vector<vector<int>>& points, int w)
{
    sort(points.begin(), points.end(), cmp);

    int counter = 0;

    int idx = 0;
    int n = points.size();

    while (idx < n)
    {
        const vector<int>& current = points[idx];

        while (idx < n)
        {
            if (points[idx][0] - current[0]<= w)
            {
                idx++;
            }

            else
            {
                break;
            }
        }

        counter++;
    }

    return counter;
}
};
