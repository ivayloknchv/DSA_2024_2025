// https://leetcode.com/problems/shortest-path-with-alternating-colors/description/

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, 
    vector<vector<int>>& blueEdges) 
    {
        unordered_map<int, unordered_set<int>> rgraph, bgraph;
        unordered_set<int> rvisited, bvisited;

        vector<int> ans(n, INT_MAX);

        for(int i = 0; i < redEdges.size(); i++)
        {
            rgraph[redEdges[i][0]].insert(redEdges[i][1]);
        }

        for(int i = 0; i < blueEdges.size(); i++)
        {
            bgraph[blueEdges[i][0]].insert(blueEdges[i][1]);
        }

        queue<pair<int, char>> q;

        q.push({0, '#'});

        int level = 0;

        while(!q.empty())
        {
            int s = q.size();

            for(int i = 0; i < s; i++)
            {
                pair<int, char> curr = q.front();
                q.pop();

                ans[curr.first] = min(level, ans[curr.first]);

                if(curr.second == '#')
                {
                    for(int neighbour : bgraph[curr.first])
                    {
                        if(bvisited.count(neighbour)==0)
                        {
                            bvisited.insert(neighbour);
                            q.push({neighbour, 'b'});
                        }
                    }

                    for(int neighbour : rgraph[curr.first])
                    {
                        if(rvisited.count(neighbour)==0)
                        {
                            rvisited.insert(neighbour);
                            q.push({neighbour, 'r'});
                        }
                    }
                }

                if(curr.second == 'r')
                {
                    for(int neighbour : bgraph[curr.first])
                    {
                        if(bvisited.count(neighbour)==0)
                        {
                            bvisited.insert(neighbour);
                            q.push({neighbour, 'b'});
                        }
                    }
                }

                if(curr.second == 'b')
                {
                    for(int neighbour : rgraph[curr.first])
                    {
                        if(rvisited.count(neighbour)==0)
                        {
                            rvisited.insert(neighbour);
                            q.push({neighbour, 'r'});
                        }
                    }
                }
            } 

            level++;
        }

        for(int i = 0; i < n; i++)
        {
            if(ans[i]==INT_MAX)
            {
                ans[i]=-1;
            }
        }

        return ans;
    }
};
