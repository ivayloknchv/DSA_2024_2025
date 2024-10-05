#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        string str;
        cin>>str;
        
        int counter[26]{};
        
        for(int i = 0; i<n; i++)
        {
            if(str[i]>='A' && str[i]<='Z')
            {
                counter[str[i]-'A']++;
            }
        }
        
        for(int i=0;i<26;i++)
        {
            if(counter[i]>=k)
            {
                cout<<(char)('A'+i);
            }
        }
        cout<<'\n';
    }
    return 0;
}
