// https://leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int> nums;

        for(string s : tokens)
        {
            if(s == "+")
            {
                int n1= nums.top();
                nums.pop();
                int n2=nums.top();
                nums.pop();
                nums.push(n2+n1);
            }
            else if(s == "-")
            {
                int n1= nums.top();
                nums.pop();
                int n2=nums.top();
                nums.pop();
                nums.push(n2-n1);
            }
            else if(s == "*")
            {
                int n1= nums.top();
                nums.pop();
                int n2=nums.top();
                nums.pop();
                nums.push(n2*n1);
            }
            else if(s == "/")
            {
                int n1= nums.top();
                nums.pop();
                int n2=nums.top();
                nums.pop();
                nums.push(n2/n1);
            }
            else
            {
                nums.push(std::atoi(s.c_str()));
            }
        }        
        return nums.top();
    }
};
