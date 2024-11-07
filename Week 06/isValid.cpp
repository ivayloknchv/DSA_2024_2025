// https://leetcode.com/problems/valid-parentheses/description/?envType=problem-list-v2&envId=stack

class Solution {
public:
    bool isValid(string str) 
    {
        stack<char> s;

        for (char ch : str)
        {
            if(ch == '(' || ch =='[' || ch == '{')
            {
                s.push(ch);
            }
            else
            {
                char current = ch;

                if(s.empty())
                {
                    return false;
                }
                if( s.top() == '(' && current == ')' )
                {
                    s.pop();
                }
                else if(s.top() == '[' && current == ']')
                {
                    s.pop();
                }
                else if(s.top() == '{' && current == '}')
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
        }

        return s.empty();
    }
};
