// https://leetcode.com/problems/non-overlapping-intervals/description/

class Solution {
public:
int eraseOverlapIntervals(vector<vector<int>>& intervals) {

    sort(intervals.begin(), intervals.end());

    int ans = 0;

    vector<int> last = intervals[0];

    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][1] <= last[1])
        {
            ans++;
            last = intervals[i];
        }
        else if (last[1]>intervals[i][0] &&  last[1]<intervals[i][1])
        {
            ans++;
        }
        else
        {
            last = intervals[i];
        }
    }

    return ans;
}
};
