// https://leetcode.com/problems/k-closest-points-to-origin/description/

struct MyCmp
{
    bool operator()(const vector<int>& lhs, const vector<int>& rhs)
    {
        long long l1 = lhs[0] * lhs[0] + lhs[1] * lhs[1];
        long long l2 = rhs[0] * rhs[0] + rhs[1] * rhs[1];
        return l1 < l2;
    }
};

class Solution 
{

public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        priority_queue<vector<int>, vector<vector<int>>, MyCmp> pq;
        vector<vector<int>> res;

        for(int i = 0; i < k; i++)
        {
            pq.push(points[i]);
        }

        MyCmp temp; 

        for(int i = k; i < points.size(); i++)
        {
            if(temp(points[i], pq.top()))
            {
                pq.pop();
                pq.push(points[i]);
            }
        }

        while(!pq.empty())
        {
            res.push_back(pq.top());
            pq.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
