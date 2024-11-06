// https://leetcode.com/problems/valid-parentheses/description/?envType=problem-list-v2&envId=stack

class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> st;

        for(int i = 0; i<s.length(); i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] =='{')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty())
                {
                    return false;
                }
                char t = st.top();

                if((s[i] == ')' && t == '(') || (s[i] == ']' && t == '[') ||
                (s[i] == '}' && t == '{'))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }    
        return st.empty();
    }
};
