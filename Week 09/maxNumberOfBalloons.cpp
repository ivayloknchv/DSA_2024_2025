// https://leetcode.com/problems/maximum-number-of-balloons/description/?envType=problem-list-v2&envId=hash-table

class Solution {
public:
    int maxNumberOfBalloons(string text) 
    {
        unordered_map<char, int> m;

        for(char ch : text)
        {
            if(ch=='b' || ch=='a' || ch=='l' || ch =='o' || ch == 'n')
            {
                m[ch]++;
            }
        }    

        int counter = 0;

        while(true)
        {
            if(m['b'] >= 1 && m['a'] >= 1 && m['l'] >= 2 && m['o'] >= 2 && m['n'] >= 1)
            {
                m['b']--;
                m['a']--;
                m['l']-=2;
                m['o']-=2;
                m['n']--;
                counter++;
            }
            else
            {
                break;
            }
        }

        return counter;
    }
};
