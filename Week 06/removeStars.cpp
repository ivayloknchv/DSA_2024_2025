// https://leetcode.com/problems/removing-stars-from-a-string/description/?envType=problem-list-v2&envId=stack

class Solution {
public:
    string removeStars(string s) 
    {
        stack<char> st;

        for(char ch : s)
        {
            if(ch!='*')
            {
                st.push(ch);
            }
            else
            {
                st.pop();
            }
        }

        string res;

        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
