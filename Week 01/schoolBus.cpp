#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

size_t counter[10000000 + 1]{};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    cin>>n;
    
    
    int max=0;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        
        if(temp>0)
        {
            if(temp>max)
            {
                max=temp;
            }
            counter[temp-1]++;
        }
    }
    
    for(int i=0;i<max;i++)
    {
        if(!counter[i])
        {
            cout<<i+1;
            return 0;
        }
    }
    cout<<max+1;
    
}
