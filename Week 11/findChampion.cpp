// https://leetcode.com/problems/remove-methods-from-project/description/

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) 
    {
        vector<int> weaker(n, 0);

        for(int i = 0; i < edges.size(); i++)
        {
            weaker[edges[i][1]]++;
        }

        int ans = -1;

        for(int i = 0; i < n; i++)
        {
            if(ans==-1 && weaker[i] == 0)
            {
                ans = i;
            }

            else if(ans!=-1 && weaker[i]==0)
            {
                return -1;
            }
        }

        return ans;
    }
};
