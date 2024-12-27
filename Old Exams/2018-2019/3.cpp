#include <bits/stdc++.h>

using namespace std;

map <string, size_t> wordMap;

int main() 
{
    string str;
    
    while(cin>>str)
    {
        wordMap[str]++;
    }
    
    for(auto& [k, v] : wordMap)
    {
        if(v==1)
        {
            cout<<k<<'\n';
        }
    }
    return 0;
}
