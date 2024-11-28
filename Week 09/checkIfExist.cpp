// https://leetcode.com/problems/check-if-n-and-its-double-exist/submissions/1465162399/?envType=problem-list-v2&envId=hash-table

class Solution {
public:
    bool checkIfExist(vector<int>& arr) 
    {
        unordered_set<int> s;

        int zerosCount  = 0;

        for(int n : arr)
        {
            if(n!=0)
            {
                s.insert(n);
            }
            else
            {
                zerosCount++;
            }
        }

        if(zerosCount>=2)
        {
            return true;
        }

        for(int n : arr)
        {
            if(s.find(2*n)!=s.end())
            {
                return true;
            }
        }    

        return false;
    }
};
