// https://leetcode.com/problems/relative-ranks/description/?envType=problem-list-v2&envId=heap-priority-queue

class Solution {
public:
    static string toStr(int rank)
{
    switch (rank)
    {
    case 1: return "Gold Medal"; break;
    case 2: return "Silver Medal"; break;
    case 3: return "Bronze Medal"; break;
    default: return to_string(rank); break;
    }

    return " ";
}

vector<string> findRelativeRanks(vector<int>& score) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<>> pq;

    for (int i = 0; i < score.size(); i++)
    {
        pq.push({ score[i],i });
    }

    vector<string> res(score.size());
    int counter=1;
    while(!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();

        res[curr.second]=toStr(counter++);
    }
    return res;
}
};
