// https://leetcode.com/problems/baseball-game/description/?envType=problem-list-v2&envId=stack

class Solution {
public:
    int calPoints(vector<string>& operations) 
    {
        stack<int> nums;

        for(string str : operations)
        {
            if(str=="D")
            {
                int newNum=2*nums.top();
                nums.push(newNum);
            }
            else if(str=="C")
            {
                nums.pop();
            }
            else if(str=="+")
            {
                int first=nums.top();
                nums.pop();
                int second=nums.top();
                nums.pop();
                nums.push(second);
                nums.push(first);
                nums.push(first+second);
            }
            else
            {
                int num = std::atoi(str.c_str());
                nums.push(num);
            }
        }

        int sum = 0;

        while(!nums.empty())
        {
            sum+=nums.top();
            nums.pop();
        }

        return sum;
    }
};
