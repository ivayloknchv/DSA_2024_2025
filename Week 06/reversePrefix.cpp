// https://leetcode.com/problems/reverse-prefix-of-word/description/?envType=problem-list-v2&envId=stack

class Solution {
public:
    string reversePrefix(string word, char ch) 
    {
        stack<char> st;
        int finalIdx=0;
        bool found = false;
        for(int i = 0; i<word.size(); i++)
        {
            st.push(word[i]);

            if(word[i]==ch)
            {
                finalIdx=i;
                found=true;
                break;
            }
        }

        if(!found)
        {
            return word;
        }
        for(int i = 0; i<=finalIdx; i++)
        {
            word[i]=st.top();
            st.pop();
        }

        return word;
    }
};
