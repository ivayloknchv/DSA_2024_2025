// https://leetcode.com/problems/number-of-recent-calls/description/?fbclid=IwAR2nyVRCaQ1ajYv7OUpAyzBYLpbMbkvZx7Ttvoj-MBv9hMpGTQtmt4DwMy0

class RecentCounter {
    queue<int> q;
public:
    RecentCounter() 
    {}
    
    int ping(int t) 
    {
        q.push(t);

        while(q.front() < t-3000)
        {
            q.pop();
        }

        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
