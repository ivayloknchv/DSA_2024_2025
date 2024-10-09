//https://leetcode.com/problems/permutation-difference-between-two-strings/description/?fbclid=IwZXh0bgNhZW0CMTEAAR0b8EZjz1lC0NZ9e1AwSoMI6Jpr6wsUSrJWxfa01O5Bs-TDEUrtOv4o28E_aem_5z9ppXTeEKw5scnwfDIMVg

class Solution {
public:
    int findPermutationDifference(string s, string t)
     {
        int indexS[26]{};
        int indexT[26]{};

        for(int i=0;i<s.size();i++)
        {
            indexS[s[i]-'a']=i;
            indexT[t[i]-'a']=i;
        }

        int ans=0;

        for(int i=0;i<26;i++)
        {
            ans+=abs(indexS[i]-indexT[i]);
        }

        return ans;
    }
};
