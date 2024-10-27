// https://leetcode.com/problems/find-smallest-letter-greater-than-target/submissions/1435472346/?envType=problem-list-v2&envId=binary-search

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) 
    {
        auto upper = upper_bound(letters.begin(), letters.end(), target);

        if (upper == letters.end())
        {
            return letters[0];
        }

        int idx = upper - letters.begin();
        return letters[idx];
    }
};
