// https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/description/?envType=problem-list-v2&envId=heap-priority-queue

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) 
    {
        vector<int> nums;

        for(int i = 0; i < times.size(); i++)
        {
            nums.push_back(i);
        }

        priority_queue<int, vector<int>, greater<int>> allSeats(nums.begin(), nums.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        vector<pair<pair<int,int>, int>> vec;

        for(int i = 0; i <times.size(); i++)
        {
            vec.push_back({{times[i][0], times[i][1]}, i});
        }

        sort(vec.begin(), vec.end());

        for(int i = 0; i < vec.size(); i++)
        {
            while(!pq.empty() && pq.top().first<=vec[i].first.first)
            {
                allSeats.push(pq.top().second);
                pq.pop();
            }

            if(vec[i].second==targetFriend)
            {
                return allSeats.top();
            }

            pq.push({vec[i].first.second, allSeats.top()});
            allSeats.pop();
        }
        return -1;
    }
};
