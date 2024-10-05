#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    int q=0;
    cin>>q;
    
    for(int i=0;i<q;i++)
    {
        int n=0;
        string str;
        cin>>n>>str;
        
        int counter=0;
        for(int j=0;j<n-1;j++)
        {
            if(str[j]==str[j+1])
            {
                counter++;
            }
        }
        cout<<counter<<'\n';
    }
    return 0;
}
