// https://leetcode.com/problems/distribute-candies/description/

class Solution 
{
public:
    int distributeCandies(vector<int>& candyType) 
    {
        unordered_map<int, int> m;

        for(int i : candyType)
        {
            m[i]++;
        }

        int maxTypes = candyType.size()/2;

        return min(maxTypes, (int)m.size());
    }
};
