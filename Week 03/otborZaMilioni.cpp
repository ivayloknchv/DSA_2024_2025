#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// https://www.hackerrank.com/contests/sda-hw-2-2023/challenges/coachsort/problem

int getPos(char ch)
{
    if(ch>='0' && ch<='9')
    {
        return ch-'0';
    }
    else if(ch>='a' && ch<='z')
    {
        return 10+ch-'a';
    }
    
    return 36+ch-'A';
}

char getCh(int pos)
{
    if(pos>=0 && pos<=9)
    {
        return '0'+pos;
    }
    else if(pos>=10 && pos<=35)
    {
        return 'a'+pos-10;
    }
    
    return 'A'+pos-36;
}

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin>>n;
    string str;
    cin>>str;
    
    int count[10+26+26]{}; 
    /*
    0-9 1 10
    10-35 a z
    36-61 A Z
    */
    
    for(int i=0; i<str.size(); i++)
    {
        count[getPos(str[i])]++;
    }
    
    for(int i=0;i<10+26+26;i++)
    {
        char ch=getCh(i);
        int reps=count[i];
        
        for(int j=0;j<reps;j++)
        {
            cout<<ch;
        }
    }
    return 0;
}
