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
    
    string str;
    int n;
    char s;
    
    cin>>str;
    cin>>n;
    cin>>s;
    
    int counter=0;
    
    for(size_t i=0; i<str.size(); i++)
    {
        if(str[i]==s)
        {
            counter++;
        }
    }
    
    int total=n/str.size()*counter;
    int k=n%str.size();
    
    for(int i=0; i<k; i++)
    {
        if(str[i]==s)
        {
            total++;
        }
    }
    cout<<total;
    return 0;
}
