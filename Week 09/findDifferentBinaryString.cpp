// https://leetcode.com/problems/find-unique-binary-string/

class Solution 
{
public:
    string findDifferentBinaryString(vector<string>& nums) 
    {
        string res;

        for(int i = 0; i<nums.size(); i++)
        {
            nums[i][i]-'0';
            res+=to_string(!(nums[i][i]-'0'));
        }

        return res;    
    }
};
