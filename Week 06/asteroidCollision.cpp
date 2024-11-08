// https://leetcode.com/problems/asteroid-collision/description/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        stack<int> st;

        for(int i = 0; i<asteroids.size(); i++)
        {
            if(asteroids[i]>0)
            {
                st.push(asteroids[i]);
            }
            else
            {
                while(!st.empty() && st.top()>0 && abs(asteroids[i])>st.top())
                {
                    st.pop();
                }

                if(!st.empty() && st.top()+asteroids[i] == 0)
                {
                    st.pop();
                }

                else if(st.empty() || st.top() < 0)
                {
                    st.push(asteroids[i]);
                }
            }
        }

        vector<int> res;

        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
