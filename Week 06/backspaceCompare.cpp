// https://leetcode.com/problems/backspace-string-compare/description/

class Solution {
public:

    stack<char> generateStack(string str)
    {
        stack<char> ans;

        for(char ch : str)
        {
            if(ch>='a' && ch <='z')
            {
                ans.push(ch);
            }
            else
            {
                if(!ans.empty())
                {
                    ans.pop();
                }
            }
        }
        return ans;
    }
    bool backspaceCompare(string s, string t) 
    {
        stack<char> s1 = generateStack(s);
        stack<char> s2 = generateStack(t);

        if(s1.size()!=s2.size())
        {
            return false;
        }

        while(!s1.empty() && !s2.empty())
        {
            if(s1.top() == s2.top())
            {
                s1.pop();
                s2.pop();
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};
