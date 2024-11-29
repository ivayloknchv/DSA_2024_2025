// https://leetcode.com/problems/repeated-dna-sequences/description/

class Solution 
{
    vector<int> powers;
public:

    void calcPowers()
    {
        powers=vector<int>(10);
        powers[0]=1;
        
        for(int i = 1; i < powers.size(); i++)
        {
            powers[i]=4*powers[i-1];
        }
    }

    int convert(char ch)
    {
        if (ch == 'A')
        {
            return 0;
        }
        if(ch == 'C')
        {
            return 1;
        }
        if(ch == 'G')
        {
            return 2;
        }
        if(ch == 'T')
        {
            return 3;
        }
        return -1;
    }

    vector<string> findRepeatedDnaSequences(string s) 
    {
        if(s.size()<10)
        {
            return {};
        }

        calcPowers();

        int rollingHash = 0;
        
        vector<string> result;
        for(int i = 0; i < 10; i++)
        {
            rollingHash += convert(s[i])*powers[9-i];
        }
        unordered_map<int, int> m;
        m[rollingHash] = 1;

        for(int i = 10; i < s.size(); i++)
        {
            rollingHash -= convert(s[i - 10]) * powers[9];
            rollingHash*=4;
            rollingHash += convert(s[i]);

            if(m[rollingHash]==1)
            {
                result.push_back(s.substr(i-9,10));
            }
            m[rollingHash]++;
        }

        return result;
    }
};
