// https://leetcode.com/problems/minimum-speed-to-arrive-on-time/description/?envType=problem-list-v2&envId=binary-search

class Solution {
public:

    bool check(const vector<int>& dist, double hour, int speed)
    {
        double sum = 0.00;

        for(int i = 0; i < dist.size() - 1; i++)
        {
            int time=dist[i] / speed;
            int rem = dist[i] % speed;

            if(rem)
            {
                sum+=time + 1;
            }
            else
            {
                sum+=time;
            }
        }

        sum += dist[dist.size() - 1]*1.00 / speed;

        return sum <= hour;
    }


    int minSpeedOnTime(vector<int>& dist, double hour) 
    {
        int maxDist=dist[0];

        for(int i = 0; i < dist.size(); i++)
        {
            maxDist=max(maxDist, dist[i]);
        }

        int l = 1;
        int r = 1000000000;

        int ans = INT_MAX;
        while(l<=r)
        {
            int mid= l + (r - l) / 2;

            if(check(dist, hour, mid))
            {
                ans = min(ans, mid);
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }

        }
        
        if(ans == INT_MAX)
        {
            return -1;
        }

        return ans;
    }
};
