// https://leetcode.com/problems/unique-morse-code-words/submissions/1467752216/?envType=problem-list-v2&envId=hash-table

class Solution 
{
public:
    int uniqueMorseRepresentations(vector<string>& words) 
    {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",
        ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",
        ".--","-..-","-.--","--.."};

        unordered_set<string> s;

        for(string& w : words)
        {
            string morse_code;

            for(char ch : w)
            {
                morse_code += morse[ch-'a'];
            }
            s.insert(morse_code);
        }

        return s.size();
    }
};
