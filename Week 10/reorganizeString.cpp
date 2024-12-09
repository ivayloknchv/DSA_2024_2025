// https://leetcode.com/problems/reorganize-string/description/

class Solution {
public:
    string reorganizeString(string s) 
    {
        unordered_map<char, int> m;

        for(auto ch : s)
        {
            m[ch]++;
        }

        priority_queue<pair<int, char>, vector<pair<int, char>>, less<>> pq;

        for(auto& it : m)
        {
            pq.push({it.second, it.first});
        }

        string res="";

        while(!pq.empty())
        {
            pair<int, char> curr1 = pq.top();
            pq.pop();

            if(!res.empty() && res.back()==curr1.second)
            {
                return "";
            }

            res+= string(1, curr1.second);

            curr1.first--;

            if(!pq.empty())
            {
                pair<int, char> curr2 = pq.top();
                pq.pop();

                res+= string(1, curr2.second);

                curr2.first--;

                if(curr2.first)
                {
                    pq.push(curr2);
                }
            }

            if(curr1.first)
            {
                pq.push(curr1);
            }
        }

        return res;
    }
};
