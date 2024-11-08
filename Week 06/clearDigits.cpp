// https://leetcode.com/problems/clear-digits/description/?envType=problem-list-v2&envId=stack

class Solution {
public:
    string clearDigits(string s) 
    {
        stack<char> st;

        for(char ch : s)
        {
            if(!st.empty() && ch>='0' && ch <='9')
            {
                st.pop();
            }
            else
            {
                st.push(ch);
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
