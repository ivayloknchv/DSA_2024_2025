// https://leetcode.com/problems/find-the-town-judge/description/

class Solution {
public:
int findJudge(int n, vector<vector<int>>& trust)
{
    vector<int> inDeg(n+1, 0);
    vector<int> outDeg(n+1, 0);

    for(int i = 0; i < trust.size(); i++)
    {
        int a = trust[i][0];
        int b = trust[i][1];
        inDeg[b]++;
        outDeg[a]++;
    }

    for(int i = 1; i <= n; i++)
    {
        if(inDeg[i]==n-1 && outDeg[i] == 0)
        {
            return i;
        }
    }

    return -1;
}
};
