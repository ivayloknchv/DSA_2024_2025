#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// https://www.hackerrank.com/contests/sda-hw-2-2022/challenges/netflix-1-1/problem

int main() {
    const int totalSize=26+26+10;
    pair<int, int> count[totalSize]{};
    
    string str;
    cin>>str;
    
    for (size_t i=0;i<str.size();i++)
    {
        if(str[i]>='a' && str[i]<='z')
        {
            count[str[i]-'a'].first++;
            count[str[i]-'a'].second=i;
        }
        else if(str[i]>='A' && str[i]<='Z')
        {
            count[str[i]-'A'+26].first++;
            count[str[i]-'A'+26].second=i;
        }
        else
        {
             count[str[i]-'0'+52].first++;
            count[str[i]-'0'+52].second=i;
        }
    }
    
    sort(count, count+totalSize);
    
    for(int i = 0; i < totalSize; i++)
    {
        if(count[i].first==1)
        {
            cout<<count[i].second<<' ';
        }
    }
    return 0;
}
