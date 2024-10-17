// https://leetcode.com/problems/minimum-processing-time/description/?envType=problem-list-v2&envId=awdekmvh

class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks)
{
    sort(tasks.begin(), tasks.end());
    sort(processorTime.begin(), processorTime.end());
    reverse(tasks.begin(), tasks.end());

    int idx = 0;
    int ans = 0;

    for (int i = 0; i<processorTime.size();i++)
    {
        ans = max(ans, processorTime[i] + tasks[idx]);
        idx += 4;
    }

    return ans;
}
};
