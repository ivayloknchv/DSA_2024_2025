// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/

class Solution {
public:
    int maxDepth(string s) 
    {
        int maxVal=0;
        stack<char> st;

        for(char ch : s)
        {
            if(ch=='(')
            {
                st.push(ch);
                if(st.size()>maxVal)
                {
                    maxVal=st.size();
                }
            }
            else if(ch==')')
            {
                st.pop();
            }
        }

        return maxVal;
    }
};
