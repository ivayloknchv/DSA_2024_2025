// https://leetcode.com/problems/intersection-of-two-arrays/description/?envType=problem-list-v2&envId=awdekmvh

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        bool contains1[1001] {};
        bool contains2[1001] {};

        for(int i=0;i<nums1.size();i++)
        {
            contains1[nums1[i]]=true;
        }
        for(int i=0;i<nums2.size();i++)
        {
            contains2[nums2[i]]=true;
        }

        vector<int> res;

        for(int i=0;i<1001;i++)
        {
            if(contains1[i] && contains2[i])
            {
                res.push_back(i);
            }
        }

        return res;
    }
};
