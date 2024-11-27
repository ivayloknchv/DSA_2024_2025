// https://leetcode.com/problems/find-occurrences-of-an-element-in-an-array/description/

class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) 
    {
        int counter=1;
        unordered_map <int, int> m;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i]==x)
            {
                m[counter++]=i;        
            }
        }    

        vector<int> ans;

        for(int q : queries)
        {
            if(m.find(q)!=m.end())
            {
                ans.push_back(m[q]);
            }
            else
            {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};
