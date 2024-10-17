// https://leetcode.com/problems/merge-intervals/description/?envType=problem-list-v2&envId=sorting&fbclid=IwZXh0bgNhZW0CMTEAAR2fbSv30MMPBtOGc16TS5F4SN5Nz68HBewfNowiJpc6YZGm-iPvteA-tQM_aem_U0VT5Khk9HKCx9BoLwQbfw

class Solution {
public:

    static bool cmp(const vector<int>& lhs, const vector<int>& rhs)
    {
        if(lhs[0]==rhs[0])
        {
            return lhs[1]<rhs[1];
        }

        return lhs[0]<rhs[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end(), cmp);

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int currentIdx=0;

        for(int i=1; i<intervals.size(); i++)
        {
            if(ans[currentIdx][1]>=intervals[i][0])
            {
                ans[currentIdx][1]=max(ans[currentIdx][1],intervals[i][1]);
            }
            else
            {
                ans.push_back(intervals[i]);
                currentIdx++;
            }
        }   

        return ans;
    }
};
