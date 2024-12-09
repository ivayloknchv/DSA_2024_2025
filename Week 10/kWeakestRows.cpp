// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/description/

struct RowInfo
{
    int soldiers = 0;
    int idx = 0;

    RowInfo(const vector<int>& row, int idx): idx(idx)
    {
        for(int r : row)
        {
            if(r)
            {
                soldiers++;
            }
        }
    }
};

struct MyCmp
{
    bool operator()(const RowInfo& lhs, const RowInfo& rhs)
    {
        if(lhs.soldiers==rhs.soldiers)
        {
            return lhs.idx < rhs.idx;
        }
        return lhs.soldiers < rhs.soldiers;
    }
};

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
         MyCmp cmp;

         priority_queue <RowInfo, vector<RowInfo>, MyCmp> pq;

         vector<RowInfo> vec;

         for(int i = 0; i<mat.size(); i++)
         {
            vec.push_back(RowInfo(mat[i],i));
         }

         for(int i = 0; i < k; i++)
         {
            pq.push(vec[i]);
         }

         for(int i = k; i < vec.size(); i++)
         {
            if(cmp(vec[i], pq.top()))
            {
                pq.pop();
                pq.push(vec[i]);
            }
         }

         vector<int> ans;

         while(!pq.empty())
         {
            ans.push_back(pq.top().idx);
            pq.pop();
         }

         reverse(ans.begin(), ans.end());

         return ans;
    }
};
