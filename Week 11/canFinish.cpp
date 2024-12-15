// https://leetcode.com/problems/course-schedule/description/

class Solution {
public:
    bool hasCycle(unordered_map<int, unordered_set<int>>& graph, 
    unordered_set<int>& visited, unordered_set<int>& ongoingPath, int curr)
    {
        visited.insert(curr);
        ongoingPath.insert(curr);

        for(int neighbour : graph[curr])
        {
            if(ongoingPath.count(neighbour))
            {
                return true;
            }

            if(visited.count(neighbour))
            {
                continue;
            }

            if(hasCycle(graph, visited, ongoingPath, neighbour))
            {
                return true;
            }
        }

        ongoingPath.erase(curr);
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        unordered_map<int, unordered_set<int>> graph;

        for(int i = 0; i < prerequisites.size(); i++)
        {
            graph[prerequisites[i][0]].insert(prerequisites[i][1]);
        }

        unordered_set<int> visited;
        unordered_set<int> ongoingPath;

        for(int i = 0; i < numCourses; i++)
        {
            if(!visited.count(i) && hasCycle(graph, visited, ongoingPath, i))
            {
                return false;
            }
        }

        return true;
    }
};
