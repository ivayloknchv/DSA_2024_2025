// https://leetcode.com/problems/longest-palindromic-substring/description/

class Solution {
public:
    string longestPalindrome(string s) 
    {
        if(s.size()<=1)
        {
            return s;
        }

        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));

        int startIdx = 0;
        int len = 0;

        for(int i = 0; i < s.size(); i++)
        {
            dp[i][i]=true;
            startIdx=i;
            len=1;
        }   

        for(int i = 0; i < s.size()-1; i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=true;
                startIdx = i;
                len = 2;
            }
        }

        for (int j = 2; j < s.size(); j++)
        { 
            for (int i = 0; i < j - 1; i++) 
            {  
                if (s[i] == s[j] && dp[i + 1][j - 1]) 
                {
                    dp[i][j] = true;
                    if (j - i + 1 > len) 
                    {
                        startIdx = i;
                        len = j - i + 1;
                    }
                }
            }
        }

        return s.substr(startIdx, len);
    }
};
