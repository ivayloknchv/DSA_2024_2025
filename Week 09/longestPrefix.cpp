// https://leetcode.com/problems/longest-happy-prefix/description/

class Solution 
{
    static constexpr long long mod = 1e9+7;
    static constexpr long long base = 31;
    vector<long long> pow;

    void calcPowers(long long maxExp)
    {
        pow.resize(maxExp+1);
        pow[0]=1;

        for(long long i = 1; i < pow.size(); i++)
        {
            pow[i] = (pow[i-1]*base) % mod;
        }
    }

public:

    string longestPrefix(string s) 
    {
        calcPowers(s.size());

        long long prefix=0;
        long long suffix=0;
        long long ans=0;

        for(int i = 0; i < s.size()-1; i++)
        {
            prefix = ((s[i] - 'a')+ (prefix*base)%mod)%mod;
            suffix = (((s[s.size()-i-1]-'a')*pow[i])%mod+suffix)%mod;

            if(suffix==prefix)
            {
                ans=i+1;
            }
        }

        return s.substr(0, ans);
    }
};
